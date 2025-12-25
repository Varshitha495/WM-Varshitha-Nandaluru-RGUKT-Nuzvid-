"""
Cloud Processing Module
Function: Ingest bin data and classify status
"""

FILL_THRESHOLD = 80

def classify_bin(bin_data):
    """
    bin_data: dict with bin_id and fill percentage
    """
    if bin_data["fill"] >= FILL_THRESHOLD:
        return "CRITICAL"
    return "NORMAL"

def process_incoming_data(bin_data):
    status = classify_bin(bin_data)

    record = {
        "bin_id": bin_data["bin_id"],
        "fill": bin_data["fill"],
        "status": status
    }

    return record

