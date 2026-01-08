# Wireless Realtime Simulation Exercises

> **Affiliation**\
> 大阪大学大学院情報科学研究科\
> The University of Osaka – Graduate School of Information Science and Technology\
> Mobile Communication Protocols

## Overview

This repository contains a set of practical exercises related to wireless communication and real-time signal processing.
Each exercise is organized in its own directory and documented independently.

## Table of Contents

-   **[Exercise 1]** [Modulation Simulation](/modulation_simulation/)
    → `/modulation_simulation/`

-   **[Exercise 2]** Visualization of Preamble Cross-Correlation
    → _To be documented_

## Execution environment
To execute the differents binaries (for context, refer to each exercices documentation), please use one of this two methods:

### 1. Docker usage [Windows/MacOS/Linux]
First, you need to install [docker](https://www.docker.com/) on your local device. Then, build the image and run a container.

```sh
docker build .
docker run -it <image_id>
```

All the compiled binaries are located to `/app` folder.

### 2. Local Makefile usage [MacOS/Linux]
#### Dependencies MacOS
```sh
xcode-select --install
# OR
brew install gcc make
```

### Dependencies Debian / Ubuntu
```sh
sudo apt update
sudo apt install build-essential
```

Then, you can build each exercice individually or build everything from root folder.

```sh
make
# OR
make -C modulation_simulation/
```