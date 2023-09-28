return {
    PATH = "prepend",
    log_level = vim.log.levels.INFO,
    max_concurrent_installers = 4,

    registries = {
        "lua:mason-registry.index",
        "github:mason-org/mason-registry",
    },

    providers = {
        "mason.providers.registry-api",
        "mason.providers.client",
    },

    github = {
        download_url_template = "https://github.com/%s/releases/download/%s/%s",
    },

    pip = {
        upgrade_pip = false,
        install_args = {},
    },

    ui = {
        check_outdated_packages_on_open = true,
        border = "none",
        width = 0.7,
        height = 0.7,

        icons = {
            package_installed = "Yes",
            package_pending = "pending",
            package_uninstalled = "No",
        },

        keymaps = {
            toggle_package_expand = "<CR>",
            install_package = "mi",
            update_package = "mu",
            check_package_version = "mc",
            update_all_packages = "mU",
            check_outdated_packages = "mC",
            uninstall_package = "mx",
            cancel_installation = "<C-c>",
            apply_language_filter = "<C-f>",
        },
    }
}

