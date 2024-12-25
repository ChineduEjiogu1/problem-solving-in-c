units = {
   "year": 60 * 60 * 24 * 365,
   "day": 60 * 60 * 24,
   "hour": 60 * 60,
   "minute": 60,
   "second": 1,
}

def format_duration(seconds):
    if not seconds: return "now"
    result = []
    for unit, value in units.items():
        count, seconds = divmod(seconds, value)
        if count == 1: result.append(f"{count} {unit}")
        if count > 1 : result.append(f"{count} {unit}s")
    *body, tail = result
    return f"{', '.join(body)} and {tail}" if body else tail