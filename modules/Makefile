FOLDERS = $(sort $(dir $(wildcard */)))
.PHONY: pack cleanall
pack cleanall: $(FOLDERS)
$(FOLDERS): FORCE
	$(MAKE) -C $@ $(MAKECMDGOALS)
FORCE: