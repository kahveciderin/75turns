FOLDERS = $(filter-out module-buildenv/, $(sort $(dir $(wildcard */))))
.PHONY: pack cleanall
export MODAPI_FOLDER=$(shell pwd)/module-buildenv
export MODAPI_INCLUDE=$(MODAPI_FOLDER)/include
export MODLINKS=$(MODAPI_FOLDER)/modapi.a
pack cleanall: $(FOLDERS)
$(FOLDERS): modapi FORCE
	$(MAKE) -C $@ $(MAKECMDGOALS) pack
modapi:
	$(MAKE) -C $(MODAPI_FOLDER) build
FORCE: