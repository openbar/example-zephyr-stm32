# OpenBar example of Zephyr on STM32

This example shows how to configure a Zephyr project with OpenBar.

> [!TIP]
> The project is based on STM32 devkits but can be adapted to any other board
> supported by Zephyr (with a few adaptations: toolchain, hal...).

## Prerequisites

If you want to flash the firmware, you will need to install some new udev rules
on your host PC:

```bash
UDEV_RULES_URL=https://github.com/zephyrproject-rtos/openocd/raw/HEAD/contrib/60-openocd.rules

# Download and install the new rules
wget -qO- ${UDEV_RULES_URL} | sudo tee /etc/udev/rules.d/60-openocd.rules

# Reload the udev rules
sudo udevadm control --reload
```

> [!NOTE]
> You only need to run these commands once.

## Usage

```bash
# Clone the repository (with submodules)
git clone --recurse-submodules https://github.com/openbar/example-zephyr-stm32.git

# Move to the freshly cloned directory
cd example-zephyr-stm32

# Configure the build (use 'make help' to see the other configurations available)
make blinky_stm32f4_disco_defconfig

# Configure the manifest project repositories (else west commands won't work)
# It only needs to be done once after the git clone!
make update

# Build the firmware
make

# Optionally, flash the firmware
make flash
```

## Project Setup

1. This project was created with the wizard using:
   - Project type: `standard`
   - Git repositories management: `submodule`
   - Configuration directory: `configs`
   - OpenBar directory: `third-party/openbar`
   - Default configuration file: `example_defconfig`

1. Next, a custom `Dockerfile` was created to include the `west` command and the
   Zephyr SDK.

1. A manifest was created in `configs/west.yml`.

1. In a `make shell`, the `west init -l configs` and `west update` commands
   were executed to initialize and fetch the repositories. They will be added
   manually as submodules (`.gitmodules`).

1. Finally, `defconfig`s files were created.

## License

This project is released under the [Unlicense](LICENSE.md).
