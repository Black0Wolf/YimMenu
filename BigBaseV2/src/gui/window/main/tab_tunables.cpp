#include "main_tabs.hpp"

namespace big
{
	void tab_main::tab_tunables()
	{
		if (ImGui::BeginTabItem("Tunables"))
		{
			ImGui::Checkbox("Disable Phone", &g.tunables.disable_phone);

			ImGui::EndTabItem();
		}
	}
}