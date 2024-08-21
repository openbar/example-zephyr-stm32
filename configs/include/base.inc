BUILD_DIR = ${OB_BUILD_DIR}/$(notdir ${APP})/${BOARD}

build:
	west build -d ${BUILD_DIR} ${APP}

OB_MANUAL_TARGETS += flash
flash: build
	west flash -d ${BUILD_DIR}

OB_MANUAL_TARGETS += clean
clean:
	rm -rf ${BUILD_DIR}

OB_MANUAL_TARGETS += mrproper
mrproper:
	rm -rf ${OB_BUILD_DIR}

OB_MANUAL_TARGETS += update
update:
	west update

# Export OB_CONTAINER_HOME during container build
OB_CONTAINER_BUILD_EXTRA_ARGS = --build-arg=OB_CONTAINER_HOME=${OB_CONTAINER_HOME}

# Allow access to USB devices for flashing
OB_CONTAINER_VOLUMES += /dev/bus/usb
