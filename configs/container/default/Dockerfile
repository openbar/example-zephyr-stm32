FROM	debian:bookworm-slim

RUN	set -x \
	&& export DEBIAN_FRONTEND=noninteractive \
	&& apt update \
	&& apt install --no-install-recommends -y \
		build-essential \
		gawk \
	&& rm -rf /var/lib/apt/lists/*
