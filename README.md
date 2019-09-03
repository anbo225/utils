# Collection of codes from famous open source repository

## CRC32C implementation from leveldb

### Building

```bash
mkdir build && cd build
cmake .. &&  make 
make test
```


### Usage
```cpp
#include "crc32c.h"

int main() {
  const std::uint8_t buffer[] = {0, 0, 0, 0};
  std::uint32_t result;

  // Process a raw buffer.
  result = crc32c::Value(buffer, 4);

  // Process a std::string.
  std::string string;
  string.resize(4);
  result = crc32c::Value(string);

  return 0;
}
```
