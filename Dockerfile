FROM rsmmr/clang:latest

RUN apt-get update && apt-get -y install --fix-missing linux-tools-generic pkg-config ; ln -f -s /usr/lib/linux-tools/*-generic/perf /usr/bin/perf;  git clone https://github.com/google/benchmark.git ; git clone https://github.com/google/googletest.git benchmark/googletest ; ( cd benchmark && mkdir build && cd build && cmake ../ -DCMAKE_BUILD_TYPE=Release && make && make install) ; rm -rf benchmark ; printf "\n\necho 0 > /proc/sys/kernel/kptr_restrict\n" >> /root/.bashrc
