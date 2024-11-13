# Image for vscode container development using local workspace

FROM ubuntu:24.04

RUN apt-get update -y && \
    apt-get install -y sudo vim git locales build-essential ccache \
    python3 python3-pip python3-venv \
    doxygen pelican texlive-latex-recommended \
    bison flex \
    qtbase5-dev libqt5svg5-dev libqwt-qt5-dev libbz2-dev \
    rapidjson-dev libboost-all-dev libeigen3-dev libxml2-dev libcairo2-dev

RUN export LC_ALL=en_US.UTF-8 && \
    export LANG=en_US.UTF-8 && \
    locale-gen en_US.UTF-8

RUN adduser developer && \
    echo "developer:developer" | chpasswd && \
    usermod -aG sudo developer

USER developer

VOLUME /home/developer/alliance

WORKDIR /home/developer/alliance

CMD ["/bin/bash"]
