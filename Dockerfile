FROM gcc:11.2.0

COPY . /usr/src/main_files

WORKDIR /usr/src/main_files

RUN g++ main.cpp -o CommandConsole

CMD [ "./CommandConsole" ]