#include "backend.hpp"
#include "script.hpp"
#include "thread_pool.hpp"
#include "looped/looped.hpp"
#include "services/context_menu/context_menu_service.hpp"
#include "script_patches.hpp"

namespace big
{
	void backend::loop()
	{
		register_script_patches();

		while (g_running) 
		{
			g->attempt_save();
			looped::system_self_globals();
			looped::system_update_pointers();
			looped::system_desync_kick_protection();
			looped::system_spoofing();
			looped::system_mission_creator();
			looped::system_auto_tp();

			script::get_current()->yield();
		}
	}

	void backend::self_loop()
	{
		LOG(INFO) << "Starting script: Self";

		while (g_running)
		{
			looped::self_clean_player();
			looped::self_free_cam();
			looped::self_godmode();
			looped::self_invisibility();
			looped::self_no_ragdoll();
			looped::self_off_radar();
			looped::self_police();
			looped::self_super_run();
			looped::self_no_collision();
			looped::self_hud();
			looped::self_unlimited_oxygen();
			looped::self_no_water_collision();
			looped::self_mobile_radio();
			looped::self_fast_respawn();
			looped::self_dance_mode();

			script::get_current()->yield();
		}
	}

	void backend::weapons_loop()
	{
		LOG(INFO) << "Starting script: Weapons";

		while (g_running)
		{
			looped::weapons_ammo_special_type();
			looped::weapons_cage_gun();
			looped::weapons_delete_gun();
			looped::weapons_force_crosshairs();
			looped::weapons_gravity_gun();
			looped::weapons_increased_damage();
			looped::weapons_infinite_ammo();
			looped::weapons_infinite_mag();
			looped::weapons_no_recoil();
			looped::weapons_no_spread();
			looped::weapons_repair_gun();
			looped::weapons_steal_vehicle_gun();
			looped::weapons_vehicle_gun();
			looped::weapons_rapid_fire();

			script::get_current()->yield();
		}
	}

	void backend::vehicles_loop()
	{
		LOG(INFO) << "Starting script: Vehicles";

		while (g_running)
		{
			looped::vehicle_auto_drive();
			looped::vehicle_boost_behavior();
			looped::vehicle_drive_on_water();
			looped::vehicle_god_mode();
			looped::vehicle_horn_boost();
			looped::vehicle_jump();
			looped::vehicle_instant_brake();
			looped::vehicle_is_targetable();
			looped::vehicle_seatbelt();
			looped::vehicle_speedo_meter();
			looped::vehicle_keep_vehicle_repaired();
			looped::vehicle_no_water_collision();

			script::get_current()->yield();
		}
	}

	void backend::turnsignal_loop()
	{
		LOG(INFO) << "Starting script: turnsignal";

		while (g_running)
		{
			looped::vehicle_turn_signals();

			script::get_current()->yield();
		}
	}

	void backend::misc_loop()
	{
		LOG(INFO) << "Starting script: Miscellaneous";

		while (g_running)
		{
			looped::hud_transition_state();
			looped::tunables_disable_phone();
			looped::session_local_time();
			looped::session_pop_multiplier_areas();
			looped::session_force_thunder();
			looped::session_randomize_ceo_colors();
			looped::session_auto_kick_host();

			script::get_current()->yield();
		}
	}

	void backend::remote_loop()
	{
		LOG(INFO) << "Starting script: Remote";

		while (g_running)
		{
			looped::player_good_options();
			looped::player_spectate();
			looped::player_remote_control_vehicle();

			script::get_current()->yield();
		}
	}

	void backend::noclip_loop()
	{
		LOG(INFO) << "Starting script: No clip";

		while (g_running)
		{
			looped::self_noclip();

			script::get_current()->yield();
		}
	}

	void backend::lscustoms_loop()
	{
		LOG(INFO) << "Starting script: Ls customs";

		while (g_running)
		{
			looped::vehicle_ls_customs();

			script::get_current()->yield();
		}
	}

	void backend::rainbowpaint_loop()
	{
		LOG(INFO) << "Starting script: Rainbow paint";

		while (g_running)
		{
			looped::vehicle_rainbow_paint();

			script::get_current()->yield();
		}
	}

	void backend::vehiclefly_loop()
	{
		LOG(INFO) << "Starting script: Vehicle fly";

		while (g_running)
		{
			looped::vehicle_fly();

			script::get_current()->yield();
		}
	}

	void backend::disable_control_action_loop()
	{
		LOG(INFO) << "Starting script: Disable Control Action";

		while (g_running)
		{
			looped::self_free_cam_disable_control_action();
			looped::self_noclip_disable_control_action();

			looped::custom_gun_disable_control_action();

			context_menu_service::disable_control_action_loop();

			script::get_current()->yield();
		}
	}
}