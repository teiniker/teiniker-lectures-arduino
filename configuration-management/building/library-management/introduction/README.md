# Library Management

PlatformIO resolves libraries automatically during the build process.

Dependencies can come from:

* Explicit declarations in `platformio.ini` (`lib_deps`)

* The built-in Library Dependency Finder (LDF), which scans `#include` directives

Typical workflow:
1. We configure dependencies in `platformio.ini` (optional but recommended).
2. PlatformIO downloads matching libraries from the registry (or other sources).
3. Libraries are stored in `.pio/libdeps/<environment>/`.
4. The active environment compiles only the libraries required by that environment.

This gives repeatable builds and avoids manually copying libraries into the project.


## Dependency Configurations

Each dependency we need must be configured in the `platformio.ini` file.

_Example:_ `platformio.ini` configuration:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino

lib_deps =
    thijse/ArduinoLog@^1.1.1
```

* `thijse/ArduinoLog`: Is the PlatformIO registry identifier (`owner/name`).

* `@^1.1.1`: Use a compatible version (>=1.1.1 and <2.0.0).

* On first build, PlatformIO installs the library automatically.


## Library Versioning

Version control is done in `lib_deps` using semantic version constraints.

Common patterns:

* Exact: `thijse/ArduinoLog@1.1.1`

* Compatible updates: `thijse/ArduinoLog@^1.1.1`

* Patch updates only: `thijse/ArduinoLog@~1.1.1`

* Range: `thijse/ArduinoLog@>=1.1.0,<2.0.0`

Validation happens when dependencies are resolved:
1. PlatformIO checks available versions in the registry.
2. It selects a version that satisfies the constraint.
3. If no version matches, the build fails with a dependency/version error.

For stable CI builds, prefer fixed or tightly constrained versions.


## References

- [PlatformIO: Library Dependency Management](https://docs.platformio.org/en/latest/librarymanager/index.html)

_Egon Teiniker, 2020-2026, GPL v3.0_