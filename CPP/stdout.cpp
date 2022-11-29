#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <memory>
#include <stdexcept>

/* Ejecuta el comando "cmd" y devuelve un string con el output */
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

int main(int argc, char* argv[]){
    return 0;
}