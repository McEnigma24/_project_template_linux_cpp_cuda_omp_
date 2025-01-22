#!/bin/bash

install_hook()
{
    DIR_SCRIPTS="scripts"
    PATH_MY_HOOK="$scripts/formating_hook.sh"
    PATH_GIT_HOOK=".git/hooks/pre-commit"

    cp $PATH_HOOK $PATH_GIT_HOOK
    chmod +x $PATH_GIT_HOOK
}

install_hook

git add .; git commit -m "quick"; git push

# git commit -am "quick"; git push # ! does not include new files !