# ssharp-hash - A hash utility for ssharp

[![License](https://img.shields.io/badge/license-Apache%202.0-blue.svg)](LICENSE)

## Overview

ssharp-hash is a utility library of ssharp to hash the string, to
resolve hashes in the SCS game asset files, also, it can be built
standalone as a simple tool for hashing string or creating a string to
hash dictionary.

ssharp-hash uses v1.0.3 of google's cityhash algorithm to implement,
since SCS software is not using the newest version of cityhash for
their games(e.g. ETS2, ATS).

## Features

- **Hash strings:** SCS uses hashes to store the filepath for their
  game assets, this feature helps recognize what paths the assets 
  stored.
- **Create string to hash dictionary:** Dictionaries helps ssharp path
  resolver to restore hashes to filepath using the pre-calculated
  results, so that it won't have to calculate them every time.
- **Work as library:** ssharp-hash library can be used not only by
  ssharp but also any kinds of lib consumer.
- **Work as standalone tool:** ssharp-hash can be built as a standalone
  tool for users to hash strings directly, and also create
  dictionaries.

## Getting Started

### Prerequisites

To build and run ssharp-hash, you need the following dependencies:

- `Meson`
- `Ninja`
- `CMake` (optional for googletest)

### Building

To build the ssharp-hash as a standalone tool, follow these steps:

```bash
meson setup build && ninja -C build
```

### Usage

As a standalone tool, it is very simple to hash a string:

```bash
ssharp-hash manifest.sii
```

It also supports multiple inputs:

```bash
ssharp-hash manifest.sii example.exe example.jpg
```

To work with SCS salt pattern (salt=12 as example):

```bash
ssharp-hash -s 12 manifest.sii
```

To get the verbose output:

```bash
ssharp-hash -v manifest.sii
```

To output the dictionary file(stored as .csv format):

```bash
ssharp-hash -o output-path.csv manifest.sii
```

To hash an empty string(please notice that it will always be the first
record of multiples):

```bash
ssharp-hash -e
```

For further details:
```bash
ssharp-hash -h
```

Each parameters can be used concurrently.

## Contacts:
 - `TLExpress`: ets2edc@gmail.com