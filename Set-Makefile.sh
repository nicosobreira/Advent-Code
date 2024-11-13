#!/usr/bin/env bash

set -euo pipefail

CURRENT_DIR="$(pwd)"

SDIR="${CURRENT_DIR}/src"

BMAKE="Base.mk"
MAKE="Makefile"

for dir in "${SDIR}"/*/; do
  dir=${dir%*/}
  if [[ ! -f "${dir}/${MAKE}" ]]; then
    echo "Copying ${BMAKE} to ${dir}/${MAKE}"
    cp -r "${BMAKE}" "${dir}/${MAKE}"
  fi
done
