def can_build(env, platform):
    if platform == "windows" or platform == "x11" or platform == "macos":
        return True
    else: return False

def configure(env):
    pass