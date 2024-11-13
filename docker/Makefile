BUILD_TYPE   = debug
VENV_PATH    = ${PWD}/.venv
SRC_DIR      = ${PWD}/..
OUT_DIR      = ${PWD}/${BUILD_TYPE}
BUILD_DIR    = ${OUT_DIR}/build
PREFIX       = ${OUT_DIR}/install

venv = . ${VENV_PATH}/bin/activate;

venv-setup:
	python3 -m venv ${VENV_PATH}

pdm-setup: venv-setup
	$(venv) pip3 install pdm
	$(venv) pdm plugin update
	$(venv) pdm sync -d --no-self

pdm-config: pdm-setup
	$(venv) pdm run meson setup ${SRC_DIR} ${BUILD_DIR} --prefix=${PREFIX} --buildtype=${BUILD_TYPE} -Dpython.install_env=prefix

pdm-config-wipe: pdm-setup
	$(venv) pdm run meson setup --wipe ${SRC_DIR} ${BUILD_DIR} --prefix=${PREFIX} --buildtype=${BUILD_TYPE} -Dpython.install_env=prefix

install: pdm-config
	$(venv) pdm run ninja -j`nproc` -C ${BUILD_DIR} install

clean:
	rm -rf ${BUILD_DIR}/*

nuke-everything:
	rm -rf ${VENV_PATH}
	rm -rf ${OUT_DIR}
	@echo "";
	@echo "Successfully nuked all files";
	@echo "\t'Ahhhh... much better!' - Duke Nukem";
