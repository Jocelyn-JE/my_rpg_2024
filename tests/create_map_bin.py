import anvil
import struct
from multiprocessing import Pool

# Define the array of pairs (check_value, write_value)
replacement_pairs = {
    "air": 1,
    "stone": 2,
    "oak_planks": 3,
    "oak_log": 4,
    "grass_block": 5,
    "barrel": 6,
    "beehive": 7,
    "bookshelf": 8,
    "cactus": 9
}

# Default value to write if the block is not found in replacement_pairs
default_write_value = 0

def process_chunk(chunk_coords):
    chunk_x, chunk_y = chunk_coords
    chunk = anvil.Chunk.from_region(region, chunk_x, chunk_y)
    data = bytearray()

    for z in range(16):  # Iterate through all z-levels
        for y in range(16):
            for x in range(16):
                block = chunk.get_block(x, z - 64, y)
                write_value = replacement_pairs.get(block.id, default_write_value)
                data.append(write_value)

    return data

if __name__ == '__main__':
    region = anvil.Region.from_file('r.0.0.mca')

    # Define chunk coordinates
    chunk_coords = [(x, z) for x in range(32) for z in range(32)]

    with Pool() as pool:
        results = pool.map(process_chunk, chunk_coords)

    with open("map.ioc", "wb") as binary_file:
        for result in results:
            binary_file.write(result)
