FROM alpine/git:1.0.10

COPY entrypoint.sh /

RUN apk add --no-cache bash

ENTRYPOINT ["/entrypoint.sh"]