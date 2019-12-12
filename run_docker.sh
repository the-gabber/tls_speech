docker run -ti --rm --network=host --cap-add=ALL --security-opt seccomp=unconfined --privileged=true  -v ~/src/:/source erokhin/cpptools:latest
