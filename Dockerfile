FROM ubuntu:latest AS build_step

RUN apt-get update && apt-get install -y make g++ libboost-all-dev libpqxx-dev nlohmann-json3-dev
WORKDIR /app
COPY src src
WORKDIR /app/src
RUN make build

FROM ubuntu:latest AS run_step

EXPOSE 1234
RUN apt-get update && apt-get install -y libpqxx-dev
WORKDIR /app
COPY --from=build_step /app/src/backend /app/backend

ENTRYPOINT [ "./backend" ]



