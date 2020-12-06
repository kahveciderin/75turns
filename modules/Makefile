FOLDERS = $(wildcard */)

main:
	for FOLDER in $(FOLDERS); do make pack -C $$FOLDER; done

clean:
	for FOLDER in $(FOLDERS); do make cleanall -C $$FOLDER; done