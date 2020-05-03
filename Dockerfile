FROM jesusvasquez333/ubuntu1804-epics-base:R3.15.5

# Copy the local IOC code
# (This could also be a git clone command)
COPY test-ioc /test-ioc

# Build the IOC
WORKDIR /test-ioc
RUN make clean && make

# Define the container entrypoint, which is the default command executed when
# the container starts
ENTRYPOINT ["/test-ioc/bin/linux-x86_64/test", "/test-ioc/iocBoot/ioctest/st.cmd"]
