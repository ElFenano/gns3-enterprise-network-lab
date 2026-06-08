FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y \
    g++ \
    iproute2 \
    iputils-ping \
    net-tools \
    curl \
    telnet \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
