# Changelog

## [1.1.0]

### Added
- Contextual callback overload: `setCallback(void (*callback)(void*), void* context = nullptr)`.
- New example `03-context` demonstrating the static function + `void*` context pattern.

### Changed
- `update()` now invokes the contextual callback (`_callbackCtx`) when set, falling back to the plain callback otherwise.
- Calling either `setCallback` overload clears the other, preventing ambiguous state.

## [1.0.1]

- Renamed library from `dv_foreach_interval` to `dv_every_interval` to better reflect its purpose and avoid confusion with the `foreach` concept.
- `setInterval()` now reschedules the next execution time immediately.
- Scheduling now advances with fixed cadence (`next += interval`) to reduce drift.
- Made interval comparison robust to `millis()` rollover using signed delta arithmetic.
- `interval == 0` is now an explicit mode: callback executes on every `update()` call.
- Clarified timing behavior and `interval == 0` semantics in README.

## [1.0.0]

- Initial version