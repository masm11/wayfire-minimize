# Wayfire Plugin to Minimize Windows

This is a plugin to minimize windows by a short-cut key on Wayfire.

## Installation

```sh
make
```

This command makes `libminimize.so`. Copy it to your favorite directory.

Copy `minimize.xml` to `/usr/share/wayfire/metadata/`.

Add the full path of `libminimize.so` to `plugins` in `wayfire.ini`.

## Usage

Default short-cut key is `<super> KEY_H`. So press the logo key and `H` key to
minimize the focused window.

## Configuration

Add this snippet to `wayfire.ini`, and configure it.

```
[minimize]
activate = <super> KEY_H
```

## Copyright

GPLv3.

## Author

masm11
