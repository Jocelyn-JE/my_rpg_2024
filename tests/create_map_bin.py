import anvil
import struct
from multiprocessing import Pool

# Define the array of pairs (check_value, write_value)
replacement_pairs = {
    "air": 1,
    "stone": 2,
    "oak_planks": 3,
    "grass_block": 5,
    "barrel": 6,
    "beehive": 7,
    "bookshelf": 8,
    "cactus": 9,
    "sand": 10,
    "dirt_path": 11,
    "grass": 12,
    "cobblestone": 13,
    "dead_bush": 14,
    "sandstone": 15,
    "smooth_sandstone": 16,
    "cut_sandstone": 17,
    "ice": 18,
    "water": 19,
    "jungle_log": 20,
    "mossy_cobblestone": 21,
    "fern": 22,
    "poppy": 24,
    "dandelion": 25,
    "wheat": 26,
    "beetroots": 27,
    "white_wool": 28,
    "oak_leaves": 32,
    "jungle_leaves": 33,
    "spruce_leaves": 34,
    "snow": 35,
    "end_stone_bricks": 36,
    "end_stone": 37,
    "dirt": 43,
    "coarse_dirt": 44,
    "rooted_dirt": 45,
    "brown_concrete_powder": 46,
    "podzol": 47,
    "brown_concrete": 48,
    "dead_brain_coral_block": 49,
    "dead_fire_coral_block": 50,
    "moss_block": 51,
    "white_concrete_powder": 52,
    "smooth_quartz": 53,
    "diorite": 54,
    "birch_planks": 55,
    "spruce_planks": 56,
    "calcite": 57,
    "dark_oak_planks": 58,
    "jungle_planks": 59,
    "lava": 65,
    "andesite": 66
}

# Default value to write if the block is not found in replacement_pairs
default_write_value = 0

def process_chunk(chunk_coords):
    chunk_x, chunk_y = chunk_coords
    chunk = anvil.Chunk.from_region(region, chunk_x, chunk_y)
    data = bytearray()

    for z in range(32):  # Iterate through all z-levels
        for y in range(16):
            for x in range(16):
                block = chunk.get_block(x, z + 62, y) # - 64 or + 62
                if (block.id == "grass_block" and str(block.properties.get('snowy')) == "true"):
                    write_value = 23
                elif (block.id == "sandstone_slab" and str(block.properties.get('type')) == "double"):
                    write_value = 15
                elif (block.id == "oak_wood" and str(block.properties.get('axis')) == 'y'):
                    write_value = 29
                elif (block.id == "oak_wood" and str(block.properties.get('axis')) == 'x'):
                    write_value = 30
                elif (block.id == "oak_wood" and str(block.properties.get('axis')) == 'z'):
                    write_value = 31
                elif (block.id == "sandstone_stairs" and str(block.properties.get('half')) == 'top'):
                    write_value = 38
                elif (block.id == "stripped_birch_wood" and str(block.properties.get('axis')) == 'y'):
                    write_value = 39
                elif (block.id == "hay_block" and str(block.properties.get('axis')) == 'y'):
                    write_value = 40
                elif (block.id == "hay_block" and str(block.properties.get('axis')) == 'x'):
                    write_value = 41
                elif (block.id == "hay_block" and str(block.properties.get('axis')) == 'z'):
                    write_value = 42
                elif (block.id == "oak_log" and str(block.properties.get('axis')) == 'y'):
                    write_value = 4
                elif (block.id == "oak_log" and str(block.properties.get('axis')) == 'x'):
                    write_value = 60
                elif (block.id == "oak_log" and str(block.properties.get('axis')) == 'z'):
                    write_value = 61
                elif (block.id == "spruce_log" and str(block.properties.get('axis')) == 'y'):
                    write_value = 62
                elif (block.id == "spruce_log" and str(block.properties.get('axis')) == 'x'):
                    write_value = 63
                elif (block.id == "spruce_log" and str(block.properties.get('axis')) == 'z'):
                    write_value = 64
                else:
                    write_value = replacement_pairs.get(block.id, default_write_value)
                # if block.id == "poppy":
                #     print(f"Block properties: {block.properties}")
                data.append(write_value)

    return data

if __name__ == '__main__':
    region = anvil.Region.from_file('r.0.0.mca_rpg')

    # Define chunk coordinates
    chunk_coords = [(x, z) for x in range(32) for z in range(32)]

    with Pool() as pool:
        results = pool.map(process_chunk, chunk_coords)

    with open("fmap.ioc", "wb") as binary_file:
        for result in results:
            binary_file.write(result)
