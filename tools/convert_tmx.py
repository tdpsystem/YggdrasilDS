#!/usr/bin/env python3

from __future__ import annotations

import argparse
import csv
import sys
import xml.etree.ElementTree as ET
from pathlib import Path


REQUIRED_LAYERS = (
    "Ground",
    "Paths",
    "Water",
    "Cliffs",
)


def parse_csv_layer(
        layer: ET.Element,
        expected_size: int,
) -> list[int]:
    data = layer.find("data")

    if data is None:
        raise ValueError(
            f"Layer '{layer.get('name')}' has no <data> element."
        )

    if data.get("encoding") != "csv":
        raise ValueError(
            f"Layer '{layer.get('name')}' must use CSV encoding."
        )

    csv_text = data.text or ""

    values: list[int] = []

    reader = csv.reader(csv_text.strip().splitlines())

    for row in reader:
        for value in row:
            value = value.strip()

            if value:
                values.append(int(value))

    if len(values) != expected_size:
        raise ValueError(
            f"Layer '{layer.get('name')}' contains "
            f"{len(values)} tiles; expected {expected_size}."
        )

    return values


def flatten_layers(
        layers: dict[str, list[int]],
        tile_count: int,
) -> list[int]:
    result = [0] * tile_count

    # Apply layers from lowest to highest.
    for layer_name in REQUIRED_LAYERS:
        layer = layers[layer_name]

        for index, tile_id in enumerate(layer):
            if tile_id != 0:
                result[index] = tile_id

    return result


def make_symbol_name(map_name: str) -> str:
    parts = map_name.replace("-", "_").split("_")

    if not parts:
        return "generatedMap"

    return parts[0].lower() + "".join(
        part.capitalize() for part in parts[1:]
    ) + "Map"


def make_guard_name(map_name: str) -> str:
    safe_name = map_name.upper().replace("-", "_")

    return f"YGG_GENERATED_{safe_name}_MAP_H"


def write_header(
        output_path: Path,
        map_name: str,
        symbol_name: str,
        width: int,
        height: int,
) -> None:
    guard = make_guard_name(map_name)
    prefix = map_name.upper().replace("-", "_")

    output_path.write_text(
        f"""#ifndef {guard}
#define {guard}

#include <nds/ndstypes.h>

#define {prefix}_MAP_WIDTH  {width}
#define {prefix}_MAP_HEIGHT {height}

extern const u16 {symbol_name}[
    {prefix}_MAP_WIDTH * {prefix}_MAP_HEIGHT
];

#endif
""",
        encoding="utf-8",
    )


def write_source(
        output_path: Path,
        header_filename: str,
        symbol_name: str,
        flattened: list[int],
        width: int,
) -> None:
    rows: list[str] = []

    for y in range(0, len(flattened), width):
        row = flattened[y:y + width]
        values = ", ".join(str(value) for value in row)
        rows.append(f"    {values},")

    array_text = "\n".join(rows)

    output_path.write_text(
        f"""#include "generated/{header_filename}"

const u16 {symbol_name}[] = {{
{array_text}
}};
""",
        encoding="utf-8",
    )


def convert_tmx(
        input_path: Path,
        header_path: Path,
        source_path: Path,
) -> None:
    root = ET.parse(input_path).getroot()

    width = int(root.get("width", "0"))
    height = int(root.get("height", "0"))

    if width <= 0 or height <= 0:
        raise ValueError("TMX map has an invalid width or height.")

    tile_count = width * height

    parsed_layers: dict[str, list[int]] = {}

    for layer in root.findall("layer"):
        name = layer.get("name", "")

        if name in REQUIRED_LAYERS:
            parsed_layers[name] = parse_csv_layer(
                layer,
                tile_count,
            )

    missing_layers = [
        name
        for name in REQUIRED_LAYERS
        if name not in parsed_layers
    ]

    if missing_layers:
        raise ValueError(
            "Missing required TMX layers: "
            + ", ".join(missing_layers)
        )

    flattened = flatten_layers(
        parsed_layers,
        tile_count,
    )

    map_name = input_path.stem
    symbol_name = make_symbol_name(map_name)

    header_path.parent.mkdir(
        parents=True,
        exist_ok=True,
    )

    source_path.parent.mkdir(
        parents=True,
        exist_ok=True,
    )

    write_header(
        header_path,
        map_name,
        symbol_name,
        width,
        height,
    )

    write_source(
        source_path,
        header_path.name,
        symbol_name,
        flattened,
        width,
    )

    print(f"Converted: {input_path}")
    print(f"Generated: {header_path}")
    print(f"Generated: {source_path}")


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Flatten CSV layers from a Tiled TMX map."
    )

    parser.add_argument(
        "input",
        type=Path,
        help="Input TMX file.",
    )

    parser.add_argument(
        "--header",
        type=Path,
        required=True,
        help="Generated header output path.",
    )

    parser.add_argument(
        "--source",
        type=Path,
        required=True,
        help="Generated C source output path.",
    )

    arguments = parser.parse_args()

    try:
        convert_tmx(
            arguments.input,
            arguments.header,
            arguments.source,
        )
    except (
            ET.ParseError,
            OSError,
            ValueError,
    ) as error:
        print(
            f"TMX conversion failed: {error}",
            file=sys.stderr,
        )
        return 1

    return 0


if __name__ == "__main__":
    raise SystemExit(main())