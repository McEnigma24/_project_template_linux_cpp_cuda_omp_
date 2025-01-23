#!/bin/bash

if [ "$(basename "`pwd`")" == "_project_template_linux_cpp_" ]; then

    if [ -n "$1" ]; then
        mkdir ../$1
        cp -ra . ../$1
        cd ../$1
        chmod +x scripts/*.sh
        chmod +x start.sh
        rm -rf .git
        rm -rf build/*
        rm -rf exe/*
        rm -rf log/*
        rm -rf output/*
        rm -rf run_time_config/*
        rm new_project.sh
        $SHELL
    else
        echo "no argument supplied"
    fi
else
    echo "wrong directory - cd _project_template_linux_cpp_"
fi