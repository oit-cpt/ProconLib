FROM ubuntu:18.04

RUN apt update && \
    apt install -y make cmake g++ clang-format python3-pip --no-install-recommends && \
    apt-get clean && rm -rf /var/cache/apt/archives/* /var/lib/apt/lists/*

RUN pip3 install setuptools wheel && \
    pip3 install cpplint

WORKDIR /src

CMD ["tail", "-f", "/dev/null"]
