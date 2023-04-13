# GDSerial

Serial library for Godot Engine using [libserial](https://github.com/wjwwood/serial)


## Supported Platforms

- Windows x86_64 (Intel / AMD 64-bit)
- Linux x86_64 (Intel / AMD 64-bit)
- macOS x86_64 (Intel Processors)

## Supported Godot Versions

- 3.5


## Adding to Project

Download the latest zip from the [Releases](https://github.com/MB3hel/GDSerial/releases) page. Add to the root of your project res folder.


## Usage


### Create an Instance

**WARNING: DO NOT USE THE SAME `GDSerial` INSTANCE FROM MULTIPLE THREADS! THIS WILL CAUSE SEGFAULTS IN GODOT ITSELF.** I have not tested using the same instance protected by a mutex, but GDNative instances do not seem to be thread safe.

```
onready var ser = preload("res://GDSerial/GDSerial.gdns").new()
```


### API

TODO