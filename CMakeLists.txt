cmake_minimum_required(VERSION 3.24)
project(Prob_lab_9_10)

set(CMAKE_CXX_STANDARD 23)

add_executable(Prob_lab_9_10 main.cpp Entitate/jocuri.cpp Entitate/Joc.h Repo/RepoJoc.cpp Repo/RepoJoc.h Test/Teste.cpp Test/Teste.h Service/Service.cpp Service/Service.h Ui/Ui.cpp Ui/Ui.h Repo/fileRepo.cpp Repo/fileRepo.h Repo/Collection.h Repo/Casa_de_marcat_file.cpp Repo/Casa_de_marcat_file.h Repo/Exception.cpp Repo/Exception.h Repo/Validator.cpp Repo/Validator.h
        Repo/Casa_de_marcat.cpp
        Repo/Casa_de_marcat.h
)
