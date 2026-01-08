FROM debian:12.12-slim AS builder

WORKDIR /build

RUN apt-get update && apt-get install -y \
    build-essential \
    make \
    && rm -rf /var/lib/apt/lists/*

COPY . .

RUN make

FROM debian:12.12-slim

WORKDIR /app

COPY --from=builder /build/modulation_simulation/simulator /app/simulator

RUN chmod +x /app/simulator

ENTRYPOINT ["/bin/bash"]
