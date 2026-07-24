# dv_every_interval

Lightweight Arduino helper to run a callback at a fixed interval.

`DV_EveryInterval` lets your `loop()` stay responsive while executing periodic tasks.

## Features

- Non-blocking periodic execution based on `millis()`
- Simple callback API
- Constructor-based usage or chainable builder-style configuration
- Tiny footprint, no external dependencies beyond Arduino core

## Installation

### Via Arduino Library Manager (recommended)

1. Open the Arduino IDE.
2. Go to **Tools > Manage Libraries...**
3. Search for **dv_every_interval**.
4. Click **Install**.

### Manual

1. Download this repository as a ZIP file.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...**
3. Select the downloaded ZIP file to install the library.

## API Reference

### `DV_EveryInterval()`
Creates an instance with `interval = 0` and no callback.
With this default value, the callback is executed on every `update()` call once a callback is set.

### `DV_EveryInterval(unsigned long interval)`
Creates an instance with an interval (milliseconds), callback not set.

### `DV_EveryInterval(unsigned long interval, void (*callback)())`
Creates an instance with interval and callback.

### `DV_EveryInterval& setInterval(unsigned long interval)`
Sets interval in milliseconds.
Special case: `interval == 0` means the callback is executed on every `update()` call.
Returns a reference to the same object to allow chaining.

### `DV_EveryInterval& setCallback(void (*callback)())`
Sets the callback function.
Returns a reference to the same object to allow chaining.

### `void update()`
Must be called as frequently as possible in `loop()`.
Checks whether the next execution time has been reached and runs the callback when needed.

## Important Behavior Notes

- The first callback execution is scheduled after one full interval.   
	*(Example: with `3000`, first callback occurs around `millis() == 3000`).*
- If `setInterval(0)` is used (or an instance is created with `interval = 0`), the callback is executed on every `update()` call.
- Use `interval = 0` only when you intentionally want per-loop execution.
- If no callback is set, `update()` does nothing when the interval elapses.
- This utility is based on `millis()`, so it is non-blocking and suitable for cooperative multitasking.

## Best Practices

- Keep callbacks short and fast.
- Call `update()` once per `loop()` iteration (or more often).

## Included Examples

- [examples/01-basic/01-basic.ino](examples/01-basic/01-basic.ino) : constructor + external callback function
- [examples/02-builder/02-builder.ino](examples/02-builder/02-builder.ino) : chainable configuration + lambda callback


## License

This project is licensed under the MIT License. See `LICENSE`.

## Author

David Vandensteen

## Repository

https://github.com/David-Vandensteen/dv-every-interval