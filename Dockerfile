FROM gcc:11.2.0

COPY . /usr/main_files

WORKDIR /usr/main_files

RUN g++ src/main.cpp -o CommandConsole

CMD [ "./CommandConsole" ]