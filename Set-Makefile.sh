#!/usr/bin/env bash

# TODO Fazer ser possível substituir ou não os `Makefile` em cada pasta

set -euo pipefail

BMAKE="Base-Makefile"
MAKE="Makefile"

CURRENT_DIR="$(pwd)"
SDIR="${CURRENT_DIR}/src"

for dir in "${SDIR}"/*/; do
  if [[ -d "${dir}" ]]; then
    if [[ -f "${dir}/${MAKE}" ]]; then
      cp -r "${BMAKE}" "${dir}/${MAKE}"
    fi
  fi
done
