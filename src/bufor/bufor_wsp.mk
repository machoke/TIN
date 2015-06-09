.PHONY: clean All

All:
	@echo ----------Building project:[ no_bufor - Debug ]----------
	@"$(MAKE)" -f "no_bufor.mk"
clean:
	@echo ----------Cleaning project:[ no_bufor - Debug ]----------
	@"$(MAKE)" -f "no_bufor.mk" clean
