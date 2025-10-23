"""
Original source found here: https://gist.github.com/lhearachel/0684387a6c315097ed3b813077be6a98
Credit to lhearachel - https://gist.github.com/lhearachel

This script gets run on build and produces the `compile_commands.json` file in the root
which provides clangd support.

Extra info on .clangd args:

"-ferror-limit=0" prevents the `fatal_too_many_errors` squiggle appearing on the first line of headers under the include dir.
"""

import json
import pathlib

home = pathlib.Path(__file__).resolve().parent.parent.parent
build = home / 'build'
src = home / 'src'
include = home / 'include'
modern_debug_src = build / 'modern_debug' / 'src'

c_flags = [
    '/usr/bin/arm-none-eabi-gcc',
]

c_commands = [
    {
        'directory': home,
        'arguments': c_flags + [
            '-o',
            modern_debug_src / pathlib.Path(file).with_suffix('.o').name
        ],
        'file': file.resolve()
    } for file in src.rglob('*.c')
]

h_commands = [
    {
        'directory': home,
        'arguments': c_flags + [
            '-o',
            modern_debug_src / 'main.o'
        ],
        'file': file.resolve()
    } for file in include.rglob('*.h')
]

all_commands = c_commands + h_commands

with open('compile_commands.json', 'w') as outfile:
    json.dump(all_commands, outfile, default=str, indent=4)