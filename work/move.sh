if [ -z "$1" ]; then
    exit 1
fi

str="$1"
dir_name="lc${str}"

mkdir -p "../${dir_name}"
cp ./work.cpp "../${dir_name}/${dir_name}.cpp"
: > ./work.cpp