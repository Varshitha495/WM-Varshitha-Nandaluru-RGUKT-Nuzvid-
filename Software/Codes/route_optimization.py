"""
Route Optimization Module
Strategy: Priority-Based Shortest Path Routing
"""

def optimize_route(critical_bins, depot_location):
    """
    critical_bins: list of dicts with location and priority
    depot_location: starting point coordinates
    """

    # Sort bins by urgency (higher fill first)
    sorted_bins = sorted(
        critical_bins,
        key=lambda x: x["fill"],
        reverse=True
    )

    route = [depot_location]

    for bin_node in sorted_bins:
        route.append(bin_node["location"])

    return route

