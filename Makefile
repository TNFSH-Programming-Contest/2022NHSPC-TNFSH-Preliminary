nothing:

import-pA:
	cmsImportTask ./pA/ -u $(if $(s), , --no-statement)
