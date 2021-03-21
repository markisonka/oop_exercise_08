#include <iostream>
#include <vector>
#include <deque>
#include <thread>
#include <sstream>
#include <memory>

#include "Processors/ConsoleProcessor.h"
#include "Processors/FileProcessor.h"

#include "Publisher.h"
#include "Figure.h"
#include "FigureFactory.h"

int main(int argc, char** argv) {
    const int buf_size = argc < 2 ? 10 : std::stoi(argv[1]);
    if (argc < 2) {
        std::cout << "Buffer size : " << buf_size << "\n";
    }

    std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer = std::make_shared<std::vector<std::shared_ptr<Figure>>>();
    Publisher pub;
    pub.AddWorker(std::make_shared<FileProcessor>());
    pub.AddWorker(std::make_shared<ConsoleProcessor>());
    std::thread thread(std::ref(pub));

    std::string command;
    while (true) {

        std::cin >> command;
        if (command == "create") {
            try {
                buffer->push_back(FigureFactory::CreateFigure(std::cin));
            } catch (std::exception& e) {
                std::cout << e.what() << "\n";
                continue;
            }
            if (buf_size == buffer->size()) {
                pub.SetBuffer(buffer);
                pub.Notify();
                buffer->clear();
            }
        } else if (command == "exit") {
            pub.Finish();
            break;
        } else {
            std::cout << "Unknown command\n";
            std::cin.ignore(32767, '\n');
        }
    }
    thread.join();
    return 0;
}
