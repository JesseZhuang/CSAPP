## Exceptions

If no appropriate `catch` is found, execution is transferred to a library function named `terminate`.

The `exception` header defines the most general kind of exception class named `exception`. Communicates only that an
exception occurred with no additional info.

The `stdexcept` header defines

- `runtime_error`
- `range_error` runtime error: result generated outside of meaningful range
- `overflow_error`
- `underflow_error`
- `logic_error`
- `domain_error`