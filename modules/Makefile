FOLDERS = $(sort $(dir $(wildcard */)))
.PHONY: pack cleanall
pack cleanall: $(FOLDERS)
$(FOLDERS): FORCE
	make -C $@ $(MAKECMDGOALS) pack
FORCE: