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
    "andesite": 66,
    "blackstone": 67,
    "polished_blackstone": 68,
    "polished_blackstone_bricks": 69,
    "gilded_blackstone": 70,
    "cracked_polished_blackstone_bricks": 71,
    "chiseled_polished_blackstone": 72,
    "coal_block": 73,
    "obsidian": 74,
    "crying_obsidian": 75,
    "dead_fire_coral": 76,
    "magma_block": 77,
    "polished_blackstone_slab": 68,
    "polished_blackstone_stairs": 68,
    "polished_blackstone_brick_slab": 69,
    "cobblestone_slab": 13,
    "cobblestone_stairs": 13,
    "cobblestone_wall": 13,
    "mossy_cobblestone_slab": 21,
    "mossy_cobblestone_stairs": 21,
    "spruce_stairs": 56,
    "oak_stairs": 3,
    "dark_oak_stairs": 58,
    "dark_oak_slab": 58,
    "spruce_trapdoor": 1,
    "jungle_trapdoor": 1,
    "stone_button": 1,
    "oak_button": 1,
    "oak_trapdoor": 1,
    "acacia_trapdoor": 1,
    "jungle_door": 1,
    "oak_door": 1,
    "azalea_leaves": 84,
    "flowering_azalea_leaves": 85,
    "yellow_terracotta": 95,
    "jungle_stairs": 59,
    "andesite_stairs": 66,
    "ladder": 1,
    "acacia_planks": 13,
    "cocoa": 1,
    "vine": 1,
    "sandstone_stairs": 15,
    "jungle_slab": 59,
    "jungle_button": 1,
    "smooth_sandstone_stairs": 16,
    "sandstone_slab": 1,
    "birch_slab": 55,
    "dark_oak_stairs": 58,
    "dark_oak_slab": 58,
    "spruce_stairs": 56,
    "glass_pane": 109,
    "orange_stained_glass": 110,
    "red_stained_glass": 111,
    "gray_stained_glass_pane": 112,
    "deepslate": 113,
    "deepslate_coal_ore": 114,
    "cobbled_deepslate": 115,
    "cobbled_deepslate_stairs": 115,
    "cobbled_deepslate_slab": 115,
    "spruce_door": 1,
    "dark_oak_trapdoor": 1,
    "spruce_slab": 56,
    "deepslate_bricks": 119,
    "cracked_deepslate_bricks": 120,
    "deepslate_brick_wall": 119,
    "white_terracotta": 121,
    "chain": 1,
    "gravel": 122
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
                elif (block.id == "stripped_oak_wood" and str(block.properties.get('axis')) == 'y'):
                    write_value = 78
                elif (block.id == "stripped_oak_wood" and str(block.properties.get('axis')) == 'x'):
                    write_value = 79
                elif (block.id == "stripped_oak_wood" and str(block.properties.get('axis')) == 'z'):
                    write_value = 80
                elif (block.id == "stripped_dark_oak_wood" and str(block.properties.get('axis')) == 'y'):
                    write_value = 81
                elif (block.id == "stripped_dark_oak_wood" and str(block.properties.get('axis')) == 'x'):
                    write_value = 82
                elif (block.id == "stripped_dark_oak_wood" and str(block.properties.get('axis')) == 'z'):
                    write_value = 83
                elif (block.id == "large_fern" and str(block.properties.get('half')) == 'lower'):
                    write_value = 86
                elif (block.id == "large_fern" and str(block.properties.get('half')) == 'upper'):
                    write_value = 87
                elif (block.id == "tall_grass" and str(block.properties.get('half')) == 'lower'):
                    write_value = 88
                elif (block.id == "tall_grass" and str(block.properties.get('half')) == 'upper'):
                    write_value = 89
                elif (block.id == "ladder" and str(block.properties.get('facing')) == 'east'):
                    write_value = 90
                elif (block.id == "ladder" and str(block.properties.get('facing')) == 'south'):
                    write_value = 91
                elif (block.id == "acacia_log" and str(block.properties.get('axis')) == 'y'):
                    write_value = 92
                elif (block.id == "acacia_log" and str(block.properties.get('axis')) == 'x'):
                    write_value = 93
                elif (block.id == "acacia_log" and str(block.properties.get('axis')) == 'z'):
                    write_value = 94
                elif (block.id == "rail" and str(block.properties.get('shape')) == 'east_west'):
                    write_value = 96
                elif (block.id == "rail" and str(block.properties.get('shape')) == 'north_south'):
                    write_value = 97
                elif (block.id == "rail" and str(block.properties.get('shape')) == 'ascending_west'):
                    write_value = 98
                elif (block.id == "rail" and str(block.properties.get('shape')) == 'ascending_north'):
                    write_value = 99
                elif (block.id == "rail" and str(block.properties.get('shape')) == 'ascending_east'):
                    write_value = 1
                elif (block.id == "rail" and str(block.properties.get('shape')) == 'ascending_south'):
                    write_value = 1
                elif (block.id == "stripped_birch_log" and str(block.properties.get('axis')) == 'y'):
                    write_value = 100
                elif (block.id == "stripped_birch_log" and str(block.properties.get('axis')) == 'x'):
                    write_value = 101
                elif (block.id == "stripped_birch_log" and str(block.properties.get('axis')) == 'z'):
                    write_value = 102
                elif (block.id == "stripped_dark_oak_log" and str(block.properties.get('axis')) == 'y'):
                    write_value = 103
                elif (block.id == "stripped_dark_oak_log" and str(block.properties.get('axis')) == 'x'):
                    write_value = 104
                elif (block.id == "stripped_dark_oak_log" and str(block.properties.get('axis')) == 'z'):
                    write_value = 105
                elif (block.id == "stripped_spruce_wood" and str(block.properties.get('axis')) == 'y'):
                    write_value = 106
                elif (block.id == "stripped_spruce_wood" and str(block.properties.get('axis')) == 'x'):
                    write_value = 107
                elif (block.id == "stripped_spruce_wood" and str(block.properties.get('axis')) == 'z'):
                    write_value = 108
                elif (block.id == "stripped_spruce_log" and str(block.properties.get('axis')) == 'y'):
                    write_value = 116
                elif (block.id == "stripped_spruce_log" and str(block.properties.get('axis')) == 'x'):
                    write_value = 117
                elif (block.id == "stripped_spruce_log" and str(block.properties.get('axis')) == 'z'):
                    write_value = 118
                else:
                    write_value = replacement_pairs.get(block.id, default_write_value)
                # if block.id == "poppy":
                #     print(f"Block properties: {block.properties}")
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
