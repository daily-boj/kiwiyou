#!/bin/bash

for required in 'MAIL' 'NAME' 'OWNER' 'REPO' 'PUSH_MESSAGE'; do
    if [ -z "${!required}" ]; then
        echo "$required is missing"
        exit 1
    fi
done

mkdir temp
cd temp
git init
git config --worktree user.name $NAME
git config --worktree user.email $MAIL
git pull https://${GITHUB_TOKEN}@github.com/$OWNER/$REPO.wiki.git
cd ../

echo "이곳에서는 각 문제를 푼 접근 방식을 확인하실 수 있습니다.\n" > Home.md

for page in $(ls -v -1); do
    filename=${page%.*}
    title=${filename//-/ }
    if [ "Home.md" != "$page" ]; then
        echo "- [$title](../$filename)" >> temp/Home.md
        echo $filename
    fi
done

cd temp
git add .
git commit -m "$PUSH_MESSAGE"
git push --set-upstream https://${GITHUB_TOKEN}@github.com/$OWNER/$REPO.wiki.git master
