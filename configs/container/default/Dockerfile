FROM	debian:bookworm-slim

ENV	ZEPHYR_VERSION=v3.7.0
ENV	ZEPHYR_SDK_VERSION=v0.16.8

# This is needed because cmake only supports "user package registry",
# so the files have to be installed in the correct home.
ARG	OB_CONTAINER_HOME

WORKDIR	/usr/local

RUN	set -x \
	&& export DEBIAN_FRONTEND=noninteractive \
	&& apt update \
	&& apt install --no-install-recommends -y \
		# OpenBar requirements
		gawk \
		make \

		# Container build requirements
		python3-pip \
		wget \
		xz-utils \

		# Zephyr requirements
		cmake \
		device-tree-compiler \
		file \
		git \
		ninja-build \
	&& rm -rf /var/lib/apt/lists/* \

	# Install west and the other python dependencies
	&& BASE_URL="https://github.com/zephyrproject-rtos" \
	&& ZEPHYR_URL="${BASE_URL}/zephyr" \
	&& pip install --break-system-packages --no-cache-dir \
		west \
		-r "${ZEPHYR_URL}/raw/${ZEPHYR_VERSION}/scripts/requirements.txt" \
	&& pip check \

	# Install the Zephyr SDK
	&& SDK_URL="${BASE_URL}/sdk-ng" \
	&& SDK_DL_URL="${SDK_URL}/releases/download/${ZEPHYR_SDK_VERSION}" \
	&& SDK_DIR="zephyr-sdk-${ZEPHYR_SDK_VERSION#v}" \
	&& SDK_FILE="${SDK_DIR}_linux-x86_64_minimal.tar.xz" \
	&& wget -q ${SDK_DL_URL}/${SDK_FILE} \
	&& wget -qO- ${SDK_DL_URL}/sha256.sum | shasum --check --ignore-missing \
	&& tar xf ${SDK_FILE} \
	&& rm -rf ${SDK_FILE} \
	&& HOME=${OB_CONTAINER_HOME} ${SDK_DIR}/setup.sh -t arm-zephyr-eabi -h -c
