FROM gcc:11.2.0

COPY . /usr/src/main_files

WORKDIR /usr/src/main_files

RUN gcc main.c -o CommandConsole

CMD [ "./CommandConsole" ]