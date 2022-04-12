#ifndef TEST_VEC_H_
#define TEST_VEC_H_

int num_tests = 10;

uint32_t op1_0[128] = {0xcef69a2b, 0xa7aaaca4, 0x76161d6f, 0x6cd1363f, 0xd17d71e3, 0x8a764653, 0x2f4fea4d, 0x15b065ec, 0xa1f405eb, 0xf34eedc0, 0x5521df50, 0xedaca48a, 0xe114e4ce, 0xff987f3f, 0x07cd1ca5, 0xefa1c255, 0x4aa5f67b, 0x690f789e, 0xfe40902c, 0x336476c5, 0xc193d1a0, 0xe7d0b789, 0x3d3c1f86, 0x41f9306f, 0x8e61d41d, 0x6cc03104, 0xda4054b0, 0xc5e0277d, 0x535b9b71, 0x4979941b, 0xfed9088a, 0xe5b86728, 0xc379c6cf, 0x11be56c5, 0x2c4faf08, 0x59bb29b9, 0x9daed860, 0xfaff3c80, 0x2f83914b, 0xe477fe6a, 0x12650eaf, 0xb8197ad3, 0x5c11993e, 0xe44ed987, 0x4c7d851a, 0x37ff98c1, 0x8764d6cc, 0x0336a92f, 0x1e2bd5bf, 0x08c3358e, 0xba9e4c91, 0x355d812a, 0x924a2626, 0x1b520a51, 0x899aa8e9, 0x3ba668cc, 0x8ae42090, 0xf7f42ec8, 0x8dcc3551, 0x3ce2d855, 0xb3836db8, 0x4bb7cc1a, 0xb8ef05ae, 0x84a180a5, 0xb8a13b1f, 0xde894f16, 0xf5f17eb1, 0x1e7d545e, 0x275df770, 0x98783978, 0x8d16aa5a, 0xc406827b, 0xd3008fb4, 0x9757c305, 0x67d408b6, 0xe2da73c1, 0xa16897ff, 0x1d2f7610, 0xf45516b8, 0x9b556d45, 0xc8dc30d2, 0x4e950b40, 0x4d889d8d, 0x3dcd07f1, 0x0d5100f3, 0x95d24c51, 0xd387f32f, 0xc4ea58c0, 0x9dd2577c, 0x9557b095, 0xb7a98c00, 0xf41affcc, 0x42eb3041, 0xc32a69f1, 0xf8f4b31c, 0x512d4837, 0xe7d69ca2, 0x3ae02680, 0xa8c69cbe, 0x595aa1c3, 0xf41ad9eb, 0xf15cdc58, 0x9cfc0660, 0x1d7ac5a5, 0x0c9062d6, 0x3cad5d04, 0x5e70595a, 0xc6c591dd, 0xc1a9bdb3, 0x7172c077, 0xbdc57653, 0xbe31c6b6, 0x29013543, 0xbb979010, 0x91446dbd, 0x8cb677e2, 0xd767fc97, 0x9e692d3f, 0x42dc0a19, 0xcc35cc87, 0xbfe6ac35, 0xea4c6a74, 0xda9bdbc0, 0x516dfacb, 0x95872a8d, 0xcc8e6833, 0x1e9f52ae, 0x89a78400};
uint32_t op2_0[64] = {0xa5f7f3fe, 0x4b33f1ff, 0x32248b8c, 0x43d092a2, 0xd1a82e59, 0x659d9659, 0xdc92191a, 0xb7559cdc, 0xf15059e6, 0x62152607, 0xb3232818, 0x700643b9, 0x95802315, 0x6a77ca64, 0x6061f3c5, 0xebaea7e5, 0x10972bbc, 0x2485c0c3, 0x2b21b541, 0xf401ee4d, 0xb8e6d34b, 0x257d7d99, 0x22b6f93c, 0x179222eb, 0xbe73680a, 0x9577e111, 0x09b6dade, 0x93bf6730, 0x1223c889, 0x819c899f, 0xc6a2d08e, 0x72ce285b, 0xdf23289a, 0x1b3a95e5, 0x9f8111a4, 0x29afb7cf, 0x87f7677a, 0x9764c775, 0x564d3f66, 0xfc27fc14, 0x82e82561, 0x0ba4ed10, 0xf7b0a156, 0x54cd414b, 0xfb432e33, 0x1854e3f0, 0x604bd433, 0xbb5c313d, 0xc4e01fa9, 0xcb7e04ec, 0xaf83621c, 0xd0d63007, 0xe0eac2a0, 0xfa6f08fb, 0x4cbdad02, 0x238bfac0, 0x47667f17, 0xb99df06c, 0xc4b67133, 0x108b77cb, 0x06615953, 0x23053125, 0x6bc841a1, 0x28d67a30};
uint32_t res_0[128] = {0xcef69a2b, 0xa7aaaca4, 0x76161d6f, 0x6cd1363f, 0xd17d71e3, 0x8a764653, 0x2f4fea4d, 0x15b065ec, 0xa1f405eb, 0xf34eedc0, 0x5521df50, 0xedaca48a, 0xe114e4ce, 0xff987f3f, 0x07cd1ca5, 0xefa1c255, 0x4aa5f67b, 0x690f789e, 0xfe40902c, 0x336476c5, 0xc193d1a0, 0xe7d0b789, 0x3d3c1f86, 0x41f9306f, 0x8e61d41d, 0x6cc03104, 0xda4054b0, 0xc5e0277d, 0x535b9b71, 0x4979941b, 0xfed9088a, 0xe5b86728, 0xc379c6cf, 0x11be56c5, 0x2c4faf08, 0x59bb29b9, 0x9daed860, 0xfaff3c80, 0x2f83914b, 0xe477fe6a, 0x12650eaf, 0xb8197ad3, 0x5c11993e, 0xe44ed987, 0x4c7d851a, 0x37ff98c1, 0x8764d6cc, 0x0336a92f, 0x1e2bd5bf, 0x08c3358e, 0xba9e4c91, 0x355d812a, 0x924a2626, 0x1b520a51, 0x899aa8e9, 0x3ba668cc, 0x8ae42090, 0xf7f42ec8, 0x8dcc3551, 0x3ce2d855, 0xb3836db8, 0x4bb7cc1a, 0xb8ef05ae, 0x84a180a6, 0x5e992f1e, 0x29bd4116, 0x28160a3d, 0x624de700, 0xf90625c9, 0xfe15cfd2, 0x69a8c375, 0x7b5c1f58, 0xc450e99a, 0xf96ce90d, 0x1af730cf, 0x52e0b77b, 0x36e8bb14, 0x87a74075, 0x54b70a7e, 0x8704152a, 0xd9735c8e, 0x731acc03, 0x78aa52cf, 0x31cef63e, 0xc637d43e, 0xbb4fc9ea, 0xf63eec6b, 0xdc7c7bac, 0x5c45bf87, 0x2acf91a6, 0xc16066df, 0x87da66fc, 0x550ef8cb, 0x44c6f391, 0xbf9783aa, 0xc3fb7093, 0xc6f9c53c, 0x561abc66, 0x4847ae62, 0x830a5993, 0x7c124166, 0x88c1a3cd, 0xf34945c7, 0x19a2c1b9, 0x8f788837, 0x48524a15, 0x5620fab1, 0x1b92d329, 0xbcecebe6, 0x89c7a468, 0x1e114a87, 0x798df7f3, 0xede154ed, 0x871594fd, 0x40c7cfda, 0x5d8ca7ea, 0xb852bf38, 0x98d8363a, 0x8f99b71b, 0xefc1c748, 0x074d2b4d, 0xa3ea5ae1, 0x9f524cf3, 0x61f97296, 0x9be883e0, 0xef939958, 0x8a67944f, 0xb27dfe30};
uint32_t op1_1[128] = {0x900bc285, 0x88bd2fab, 0x39e0b43e, 0x69f4a750, 0x5d8d3646, 0xc97e3e9d, 0xb828c7a1, 0xa67032db, 0xd04630ca, 0xf89b4522, 0x32715984, 0x70c2f16b, 0xd17da9dc, 0xef1d3a0d, 0x459121c5, 0xd7f78a7c, 0x3b2dc428, 0x25cd7531, 0xe5925470, 0x66a7f907, 0x3bd7fc7c, 0x1f2fbe4b, 0x0a19b5e6, 0x89682e7e, 0x93d41f90, 0x306150be, 0x64c1bd5f, 0x46c81fde, 0x9a7a1517, 0xfe1b40fb, 0x61fed965, 0x7312dd2b, 0xb5a674e6, 0x2206f268, 0xaadfb01f, 0xd2034830, 0x6aeb0f52, 0x64e31ef0, 0x93eee871, 0x88770096, 0x9e2c64fe, 0xc9edeada, 0x107203a5, 0xeab659b5, 0xb018535f, 0xec86a9dc, 0xccce7176, 0xa182b730, 0xf6a5f7a4, 0xc341f7ea, 0x982890a8, 0xcd49d671, 0x75f71fad, 0xb1ddcd90, 0x52fe2ed1, 0xd8cc9fce, 0x60d63939, 0x13cacc74, 0xb16b5672, 0x4d378dd1, 0x77d10c9b, 0x1ef049d0, 0x42e1a134, 0xac0c1100, 0x3ee03004, 0x6173cdb1, 0x6c49df30, 0x3dedf8c7, 0xceca5207, 0x8a01c399, 0x3659debe, 0x75e14243, 0x16f780b7, 0x537f142b, 0x07e4719b, 0xb1e0edb7, 0x69d0c7bf, 0x88161271, 0xea8c1636, 0x3a071be7, 0x204bbae6, 0x1d0c310a, 0x8d1296aa, 0xf40b6cc7, 0x46dd5f4d, 0x2b8692c9, 0xca501d7a, 0x7f2d35ae, 0x13d0273a, 0xb77cbf0f, 0x9eb64282, 0xcb23deaa, 0x6939df18, 0x3aecc238, 0x78e2831f, 0xdbd591a2, 0xaf32c18b, 0x17f712aa, 0x3d5ac841, 0x85874c6f, 0x65e60bde, 0xb7a26b62, 0xa168374a, 0xd8de35c9, 0xf6e7b84a, 0x535e8d3b, 0xcce3d5c0, 0x50045bc3, 0x578c9474, 0x766913ad, 0xc2aea84d, 0x1ef873e5, 0x21d6579a, 0x58d2fc70, 0x6abfb417, 0x0d35d743, 0xce848b1d, 0x04e3094e, 0x29c67c3d, 0xe0665982, 0x6527feee, 0x577c0a82, 0x8dc81527, 0xa967c02c, 0x3fbb6ee2, 0xd8299218, 0xa3dba6e6, 0x9e22da4a};
uint32_t op2_1[64] = {0xc1c3a74f, 0x885bfaf5, 0x22e25f24, 0x8a1dabeb, 0x61bceaf6, 0x66cfd9ec, 0xce72aa90, 0x070df854, 0xd44bbb12, 0xb40099a8, 0x7e003f5a, 0xdafffa0f, 0x0681d7c8, 0x11746089, 0xf67b6250, 0x3ac68840, 0xabd7f41f, 0x1ace91dc, 0xa89b7387, 0xe11a2859, 0x5b8a8a87, 0xe611c9c4, 0xbfc0a76d, 0xbabb0c2c, 0x9375c9d3, 0xe6b9c473, 0x6d67c33c, 0xaed21837, 0xc940675d, 0x059641ac, 0x3508b97d, 0xb994fd93, 0x8eb3ebb4, 0xa3db11e8, 0x1c5741e8, 0x5243c7a7, 0x5b395aa9, 0x577be104, 0xb781f916, 0x6e23c2e0, 0x1d897005, 0x7b21a3a8, 0xa2e38470, 0x863907dc, 0xc7367f2e, 0xd2c9240b, 0x9b489e7a, 0xac9dfcf1, 0x9da5b52e, 0x3bffcf1f, 0x36501876, 0x45b95a62, 0x4503dc22, 0xa5c65e46, 0x035121b6, 0x88af5dcb, 0x0f1524d4, 0xc84b1b8a, 0xbba368f2, 0xc846122f, 0x8eda305c, 0xf1e0024a, 0x0ebbddb5, 0xda5b9837};
uint32_t res_1[128] = {0x900bc285, 0x88bd2fab, 0x39e0b43e, 0x69f4a750, 0x5d8d3646, 0xc97e3e9d, 0xb828c7a1, 0xa67032db, 0xd04630ca, 0xf89b4522, 0x32715984, 0x70c2f16b, 0xd17da9dc, 0xef1d3a0d, 0x459121c5, 0xd7f78a7c, 0x3b2dc428, 0x25cd7531, 0xe5925470, 0x66a7f907, 0x3bd7fc7c, 0x1f2fbe4b, 0x0a19b5e6, 0x89682e7e, 0x93d41f90, 0x306150be, 0x64c1bd5f, 0x46c81fde, 0x9a7a1517, 0xfe1b40fb, 0x61fed965, 0x7312dd2b, 0xb5a674e6, 0x2206f268, 0xaadfb01f, 0xd2034830, 0x6aeb0f52, 0x64e31ef0, 0x93eee871, 0x88770096, 0x9e2c64fe, 0xc9edeada, 0x107203a5, 0xeab659b5, 0xb018535f, 0xec86a9dc, 0xccce7176, 0xa182b730, 0xf6a5f7a4, 0xc341f7ea, 0x982890a8, 0xcd49d671, 0x75f71fad, 0xb1ddcd90, 0x52fe2ed1, 0xd8cc9fce, 0x60d63939, 0x13cacc74, 0xb16b5672, 0x4d378dd1, 0x77d10c9b, 0x1ef049d0, 0x42e1a134, 0xac0c1101, 0x00a3d753, 0xe9cfc8a6, 0x8f2c3e54, 0xc80ba4b3, 0x30873cfd, 0xf0d19d86, 0x04cc894e, 0x7cef3a97, 0xeb433bca, 0x077fadd3, 0x85e4b0f6, 0x8ce0e7c6, 0x70529f87, 0x998a72fb, 0xe1077886, 0x74cda427, 0xcc23af05, 0x37dac2e7, 0x35ae0a32, 0xd5259520, 0xa267e9d5, 0x11985c8e, 0x8a10c4e8, 0x39e841da, 0xa745f10e, 0x9e368383, 0x0c1e05bf, 0x79f5f6e2, 0x327a4675, 0x408303e4, 0xadeb3c9d, 0x956a8f36, 0x3de6ad3f, 0xbbd22492, 0x59b20a29, 0xd7cb1416, 0xc11f6688, 0x0f1e4c67, 0x58ea3061, 0x4701f8aa, 0x1471284f, 0xce8030e4, 0x6fc75a30, 0xd63d63a0, 0x1ec313a3, 0x493237b9, 0x5df746c7, 0xcb9670d6, 0xbf7c0cc8, 0x94d2cb8f, 0xa10fcc8d, 0x52ef31a6, 0x1388673f, 0xaaa96794, 0x2d179df4, 0x6915b74d, 0x743d23c3, 0x1fc7260d, 0x496b7e1a, 0x71add25b, 0xce959f3f, 0xca099462, 0xb297849c, 0x787e7281};
uint32_t op1_2[128] = {0x9a40d81c, 0xc3b5360d, 0x98881633, 0x6c800e54, 0x0f47fa8a, 0xce08fc73, 0x99cda8ab, 0x7d1feea8, 0xa58bbbeb, 0x7cd7b3c2, 0x65224470, 0xbc4048da, 0x0e7f7d7b, 0x6fe76d51, 0xa2f00a74, 0xf81d0485, 0xd2abc8cb, 0x0eccf561, 0xcde1c1b8, 0xc992e5b6, 0xec61b1e9, 0x7a45f043, 0x0210cbe5, 0x1a09e9e5, 0xf15067c1, 0xf3c38b9d, 0x44b35309, 0x84d0a4fd, 0xde47cf6b, 0x73af989b, 0x9383c521, 0x91e03b71, 0xdebda4c4, 0x16437785, 0xbe3b6ab9, 0x1bf13a43, 0x254c6e66, 0xac28faab, 0x463fbe4c, 0x05526912, 0xc90047c7, 0x6a6ea89b, 0x237920b0, 0xb723ed04, 0x4eee2c9f, 0x682d26ec, 0x6381dccb, 0xb1e49a40, 0x2113b26b, 0x69458be3, 0x5f265b7d, 0xc083e903, 0x5a8023a7, 0x60e524b2, 0x58de2838, 0x672a6c39, 0x54fd6726, 0x744c50de, 0x68dd699e, 0x281389f7, 0xb07fde02, 0xdc353708, 0x867a649f, 0x97c5fc2c, 0xb2c66dce, 0x40c11384, 0x5c3ea7da, 0x67f23a77, 0x67d8343f, 0x3d7fa6f6, 0x1f54993b, 0x20727f2a, 0xacc9abeb, 0xc4ee99f8, 0x3e8e654e, 0xed9f7559, 0xa9204ce5, 0x078baaa1, 0x8d49eee4, 0x5e6769ab, 0xb66c6813, 0x0a16882b, 0x2688908e, 0x10905787, 0xe8ff774d, 0xecda2a02, 0x600b516c, 0xecbc2c35, 0x2980e528, 0x8b8b961d, 0x400e7379, 0x2f69fdab, 0xfe1f4f77, 0xb7faf80b, 0x4cd231c9, 0x967f2773, 0x26c437c6, 0x31192be3, 0xe5ecdf00, 0xeea54b3a, 0xd3da2ce7, 0xfb3acd42, 0xb649e671, 0x0441ce3c, 0x9fe6b702, 0xd9b0ba06, 0xcc0cabb3, 0x00d88de7, 0x0543c5fe, 0x1c7681c6, 0x3e7b81b9, 0x9a6ccccf, 0x8a4164b8, 0xe2f72835, 0x3ba46256, 0xf782b260, 0x00d3dbf3, 0x81e61474, 0x716913c4, 0xc124f4ad, 0xa97a91e3, 0x15b32825, 0xf7d8185a, 0x134bc79d, 0x010b4a7a, 0x7694ce3f, 0x4cd109b2, 0x44b28fbe};
uint32_t op2_2[64] = {0xc38fe5a9, 0x5518bec1, 0xcd5024da, 0x67b1c1d4, 0x49383705, 0x5b69a20e, 0xdeffe37e, 0x5ceff39a, 0xf10d6127, 0xd59afea9, 0x37c87d73, 0x6fcdfb89, 0xd561650f, 0x020bdcba, 0xd7110acc, 0x9b53df4c, 0x436d363b, 0x8d2213ab, 0x02243fae, 0x01edd692, 0x0db5fd6f, 0x269f0f6f, 0x63756e13, 0xa3baa122, 0x2ddc938d, 0x0a1e4f34, 0x9a90a757, 0x3309b1f8, 0xc5fedc02, 0xe84917a6, 0x598d3a92, 0xffc72519, 0xc75f56b4, 0x90ff03df, 0xf57eadec, 0x2d2da82d, 0x99c67099, 0xaec30d52, 0xfb4cce34, 0x0ebe6a3f, 0xe84d7046, 0xfca164e0, 0xd7881247, 0x390b8b33, 0x36dd4619, 0xe39e3444, 0x5615413b, 0x383a5a09, 0x9978e484, 0x4317ec2c, 0x8bd56f69, 0xc3d80db4, 0x6324a33f, 0x3f49437d, 0x61d21c84, 0x49c83e27, 0xb4e972d1, 0x48f5a2d0, 0x20408998, 0x0878a1d9, 0x6fffb965, 0x7e7803e9, 0xe3aa3cf8, 0x65c798c0};
uint32_t res_2[128] = {0x9a40d81c, 0xc3b5360d, 0x98881633, 0x6c800e54, 0x0f47fa8a, 0xce08fc73, 0x99cda8ab, 0x7d1feea8, 0xa58bbbeb, 0x7cd7b3c2, 0x65224470, 0xbc4048da, 0x0e7f7d7b, 0x6fe76d51, 0xa2f00a74, 0xf81d0485, 0xd2abc8cb, 0x0eccf561, 0xcde1c1b8, 0xc992e5b6, 0xec61b1e9, 0x7a45f043, 0x0210cbe5, 0x1a09e9e5, 0xf15067c1, 0xf3c38b9d, 0x44b35309, 0x84d0a4fd, 0xde47cf6b, 0x73af989b, 0x9383c521, 0x91e03b71, 0xdebda4c4, 0x16437785, 0xbe3b6ab9, 0x1bf13a43, 0x254c6e66, 0xac28faab, 0x463fbe4c, 0x05526912, 0xc90047c7, 0x6a6ea89b, 0x237920b0, 0xb723ed04, 0x4eee2c9f, 0x682d26ec, 0x6381dccb, 0xb1e49a40, 0x2113b26b, 0x69458be3, 0x5f265b7d, 0xc083e903, 0x5a8023a7, 0x60e524b2, 0x58de2838, 0x672a6c39, 0x54fd6726, 0x744c50de, 0x68dd699e, 0x281389f7, 0xb07fde02, 0xdc353708, 0x867a649f, 0x97c5fc2d, 0x76565377, 0x95d9d246, 0x298eccb4, 0xcfa3fc4b, 0xb1106b44, 0x98e94904, 0xfe547cb9, 0x7d6272c5, 0x9dd70d13, 0x9a8998a1, 0x7656e2c2, 0x5d6d70e3, 0x7e81b1f4, 0x0997875c, 0x645af9b0, 0xf9bb48f7, 0xf9d99e4e, 0x97389bd6, 0x28acd03c, 0x127e2e19, 0xf6b574bd, 0x13793971, 0xc380bf80, 0x9076cd57, 0x575d78b5, 0x95a9e551, 0xda9f1ad0, 0x6273afa4, 0xc41e2b7a, 0xa0440fb1, 0xa65f6c5c, 0x96464c8c, 0xee238e7a, 0xc2182fc3, 0xdb6b8ced, 0x1bd2f368, 0x6da09d81, 0xa9fdda95, 0xb196b4a5, 0x1300387c, 0x88342749, 0xd6521ee7, 0xa394bdfa, 0x39e4191a, 0x3c210c18, 0x0014b60a, 0x9490c2f4, 0xd2a726d9, 0x23ba493d, 0x260f1461, 0xc779d1c0, 0xbb5ac014, 0x63f87f32, 0xc12f57f1, 0xd33b3049, 0x0aed32d5, 0x5e6404b4, 0x5ea8caf6, 0x1818a1f2, 0x1bc46976, 0x710b03df, 0xf50cd229, 0x307b46aa, 0xaa7a287e};
uint32_t op1_3[128] = {0xd17ec6a2, 0x3a998e65, 0x4c01a80a, 0x88fad925, 0xfb6a21ac, 0xd23643ac, 0xc21f0658, 0xc8188996, 0xf16779b3, 0xacc8e849, 0x36884487, 0xafe45ffc, 0xbb9cbf57, 0xa3494dcf, 0x9cc7f002, 0x50e95ef3, 0x28e40ea1, 0x55299fe9, 0x5682b50d, 0xd5f65e2e, 0x1151c072, 0x53dabf01, 0x40b8a434, 0x880b125f, 0x03143c8a, 0x9e8c5b78, 0x0e0654e2, 0xaf166058, 0x08ef9df6, 0xa5fa421b, 0x2c6fece1, 0x8fed5989, 0xee44427d, 0x8c08bc4f, 0xf29ec257, 0xc8416478, 0xea63afce, 0x71113996, 0x2d73085e, 0x54831b1d, 0x182c5462, 0x3c6a3bce, 0xfe41e24f, 0x84af5931, 0xc35a99bf, 0x58a485d5, 0x25ffd8a4, 0xe31c5070, 0x5edac48f, 0x175de1de, 0x29090044, 0xfea13976, 0xfc3b1f44, 0xf6456c0c, 0x92a23eaf, 0x0ea59130, 0xc3017d9c, 0x47fc4797, 0xf1bee65f, 0xf235735f, 0x4edc9a4a, 0x521834c4, 0x561915f5, 0x9352afc4, 0x351007e2, 0xd150ee2e, 0x7755bd92, 0x4ee70253, 0x44dd2048, 0x16c44885, 0x6d330f7a, 0x63b280ac, 0x4edf6a0f, 0xd5fb4be3, 0x4334243d, 0x0dafa867, 0xc5d002e9, 0xee581a4b, 0x6e97bb73, 0xe3eab7bc, 0x46251822, 0x71296fcb, 0x1f2df705, 0xd482f3f9, 0x6c6b3c76, 0x52a72b23, 0x81c95a82, 0xad1e643e, 0xf0e50b2c, 0x4cfa35cd, 0xff392341, 0x1f1e0d35, 0xd91ae8bc, 0x160a2632, 0xc21eee43, 0xdf25970f, 0x8021d4b7, 0x65610910, 0x771b6d42, 0xbf96d623, 0xece49ed3, 0x4ff15684, 0xa4050c01, 0x35e3dae3, 0x7a32f693, 0x4fa1167d, 0x7650575a, 0x4fe75a49, 0xf30f9ced, 0xd48a833f, 0xd7143c6d, 0xd7539d19, 0xf4d63353, 0x9cc6615d, 0x8081e4c6, 0xda49250d, 0x78dbd48d, 0x49d41b6b, 0xc9fd70a8, 0x1d4edb06, 0xc95dadba, 0x2873627b, 0x914ee679, 0x3b7ce9a2, 0xa392a40b, 0x9534ce55, 0x9101d7aa, 0x7a60cda5};
uint32_t op2_3[64] = {0xcd41350b, 0x7135da7d, 0xe02f5be7, 0x91bf107f, 0x81faac45, 0x0119b507, 0xe0957eef, 0xe6fb19b0, 0xe95097d1, 0x13f226b6, 0xbd823787, 0x8d4d1e26, 0x778330a0, 0xe97381ed, 0x28762ad4, 0xd1df2359, 0x92af5c90, 0xa9eaccf6, 0x13865a53, 0x5a5522b9, 0x5f879be4, 0x18ad6317, 0x77710cba, 0x9974df06, 0xe8ebdbd8, 0x7c8e47dd, 0x9c45a07e, 0x6d0e5dc7, 0x76ac80d3, 0x8752d38a, 0xe91833fe, 0x2d200888, 0xc8ea9cbd, 0xcacd3fca, 0x3f7f3aca, 0x4acec60e, 0x7f09475d, 0x3a95f7fb, 0xc911aa11, 0x0ba3dfc7, 0x1b24d3f2, 0x4b3e44a4, 0x671e72d6, 0x895782bf, 0xd80bb897, 0x8edca3d8, 0x52d268b0, 0x475b42c9, 0x78101cd5, 0x670941d3, 0xd46ee50c, 0x2fe9268d, 0x06d89406, 0xf552a7a3, 0xcfe2415c, 0xcf09b440, 0xae867ed7, 0x6aeee71a, 0x9c7e3646, 0x4e636374, 0x2ab30927, 0x3e127db4, 0xba539670, 0x255e0306};
uint32_t res_3[128] = {0xd17ec6a2, 0x3a998e65, 0x4c01a80a, 0x88fad925, 0xfb6a21ac, 0xd23643ac, 0xc21f0658, 0xc8188996, 0xf16779b3, 0xacc8e849, 0x36884487, 0xafe45ffc, 0xbb9cbf57, 0xa3494dcf, 0x9cc7f002, 0x50e95ef3, 0x28e40ea1, 0x55299fe9, 0x5682b50d, 0xd5f65e2e, 0x1151c072, 0x53dabf01, 0x40b8a434, 0x880b125f, 0x03143c8a, 0x9e8c5b78, 0x0e0654e2, 0xaf166058, 0x08ef9df6, 0xa5fa421b, 0x2c6fece1, 0x8fed5989, 0xee44427d, 0x8c08bc4f, 0xf29ec257, 0xc8416478, 0xea63afce, 0x71113996, 0x2d73085e, 0x54831b1d, 0x182c5462, 0x3c6a3bce, 0xfe41e24f, 0x84af5931, 0xc35a99bf, 0x58a485d5, 0x25ffd8a4, 0xe31c5070, 0x5edac48f, 0x175de1de, 0x29090044, 0xfea13976, 0xfc3b1f44, 0xf6456c0c, 0x92a23eaf, 0x0ea59130, 0xc3017d9c, 0x47fc4797, 0xf1bee65f, 0xf235735f, 0x4edc9a4a, 0x521834c4, 0x561915f5, 0x9352afc5, 0x02513cee, 0x4286c8ac, 0x57851979, 0xe0a612d2, 0xc6d7cc8d, 0x17ddfd8d, 0x4dc88e6a, 0x4aad9a5d, 0x383001e0, 0xe9ed729a, 0x00b65bc4, 0x9afcc68e, 0x3d53338a, 0xd7cb9c38, 0x970de648, 0xb5c9db15, 0xd8d474b3, 0x1b143cc1, 0x32b45159, 0x2ed816b2, 0xcbf2d85a, 0x6b548e3a, 0xf93a673d, 0x46934345, 0xd9d0e704, 0xc9887dab, 0x9b7ec3bf, 0x8c2c6afd, 0x4fc7698f, 0x9d5cf9bd, 0xab372242, 0x0c459f98, 0x490c7175, 0x302e48da, 0xb69aa80d, 0x0a659c32, 0x6bede630, 0x8a874e80, 0x6d16b612, 0x4187baaa, 0x9557ca85, 0x9adf5b21, 0xdd6eca30, 0xd93edd09, 0xcb1b5585, 0x63672718, 0x29e6a51e, 0x1eaedfe3, 0x6ce65029, 0x03cfa331, 0x54f0c9d3, 0x0a324b9a, 0x7fb46894, 0x3f26c30f, 0x99dfb204, 0xec588f47, 0x77e42c91, 0x93624996, 0x2dcd1cbf, 0x89e04d16, 0xce45ad32, 0xd3474c0a, 0x4b556e1a, 0x9fbed0ab};
uint32_t op1_4[128] = {0x8fb19b65, 0x80127114, 0xcb526d52, 0x05a0a4f2, 0x9a47b2fd, 0xe963dd59, 0x6b42527e, 0x44fdc857, 0x0fc67255, 0x712731ef, 0x7c151c73, 0xb3d0483b, 0x541097fd, 0x1c6b2554, 0x9636ffb2, 0x6360ab18, 0xe0fd0320, 0xb3e3ab25, 0x81f2171e, 0x9a690345, 0x28560e52, 0xa046cd9e, 0x4747063c, 0xb73d8322, 0xd41c6cc1, 0x4bd0cc45, 0xf01aa13e, 0x6e24ee02, 0x8c644c67, 0xfbaa0a69, 0xd6deeaf7, 0x60a37e2c, 0x3a2dcc52, 0x1065d11c, 0x66cdaaaa, 0x20f4ea35, 0x31066da3, 0xcc40041c, 0x7f05f001, 0x3af88170, 0x322a0bf4, 0xad4178aa, 0x3ef25309, 0xa59a07ae, 0xab1e9e79, 0x0ec4bd31, 0x7e0d0a83, 0x2c3009d8, 0x4a157237, 0xaa194909, 0x2481c8c1, 0x7b896259, 0xac994611, 0x3960ec97, 0x6c54eb6a, 0x58834127, 0x598c60ee, 0xb13ab9c4, 0x6aa9d9a5, 0xf5eb2cc2, 0x5b4de174, 0xdeaac61e, 0x3795623f, 0xcc973652, 0xb3a6dbc2, 0x05f4d2a0, 0x222329d2, 0x0ec4dded, 0x6500255c, 0x066798d8, 0x141f9929, 0x1ebdb20e, 0x7fb7f719, 0x6e4501ac, 0xbebc3615, 0xc3ed1739, 0x79d8ab88, 0x1092fbc4, 0x3cb69fc8, 0x44c216de, 0x7692005a, 0xb39c7e2f, 0xe7eeac00, 0x25b43807, 0x56cdb454, 0x52e99ef1, 0x74de2650, 0xf5337b90, 0x7bae091a, 0x7df80433, 0x9dfeb1db, 0x1c89b049, 0x8e7aa784, 0xbd698343, 0xe00b16ad, 0x0e3f207e, 0xd0e94c83, 0xb7fcdbaa, 0x8e1c39a7, 0x320701e6, 0x4a9553eb, 0x5e8a5cbe, 0xec901733, 0xb6d6cc93, 0x1a653aa8, 0xb209eac1, 0xfc56f841, 0xb4568218, 0xec926e11, 0x3e429a45, 0x5f41c6e3, 0x944a8307, 0x6b4f56d9, 0x7aac1756, 0x1e645415, 0x891dbc41, 0x754dc16a, 0x92ff925d, 0x6ef3efb8, 0xe3f16d26, 0xaaea6bd6, 0xe3213309, 0x60a12fda, 0x17d88d43, 0x01443612, 0x619cf9ea, 0x793086f5, 0xafc5d0a7};
uint32_t op2_4[64] = {0xff0e728e, 0xb632129f, 0x2949e90a, 0x82aae26b, 0x3c85c9c7, 0x61df9865, 0x2863f71d, 0x1e0af7d0, 0x25522862, 0x94a06083, 0x14017631, 0x89948880, 0x72062af3, 0x07c331af, 0x5f35c634, 0x01e02a7e, 0xfe9aca69, 0xea5150f2, 0x09004013, 0x0e27b943, 0x71430175, 0xd4200968, 0x58a3c806, 0xb53b173a, 0x849ec5d0, 0x3ccbfe71, 0x1c1b4196, 0x6fd372e9, 0xaea3cfef, 0x1331d1a3, 0x2eaacaf0, 0x596e7e99, 0xbbc79090, 0xf744b356, 0x728f9b95, 0xe9f54d6e, 0x6f3cc347, 0xcf2ee93c, 0xb6cae7d8, 0xa46d70f2, 0x347f54e2, 0xd34aae95, 0xc2aff5fd, 0xe8f91acc, 0x52c98fd4, 0x910617bc, 0x2391de4c, 0xfae8c29e, 0x5345e1cf, 0xb4ff947f, 0xf78781d2, 0x5b786ccf, 0x12b879ae, 0x5834681c, 0x80f7b62e, 0xb757a808, 0xd83a1177, 0xf0b6b66f, 0x6577b8fa, 0x86641b0c, 0x6a789ef7, 0x9b1462ba, 0xd81a6a2a, 0x4256849d};
uint32_t res_4[128] = {0x8fb19b65, 0x80127114, 0xcb526d52, 0x05a0a4f2, 0x9a47b2fd, 0xe963dd59, 0x6b42527e, 0x44fdc857, 0x0fc67255, 0x712731ef, 0x7c151c73, 0xb3d0483b, 0x541097fd, 0x1c6b2554, 0x9636ffb2, 0x6360ab18, 0xe0fd0320, 0xb3e3ab25, 0x81f2171e, 0x9a690345, 0x28560e52, 0xa046cd9e, 0x4747063c, 0xb73d8322, 0xd41c6cc1, 0x4bd0cc45, 0xf01aa13e, 0x6e24ee02, 0x8c644c67, 0xfbaa0a69, 0xd6deeaf7, 0x60a37e2c, 0x3a2dcc52, 0x1065d11c, 0x66cdaaaa, 0x20f4ea35, 0x31066da3, 0xcc40041c, 0x7f05f001, 0x3af88170, 0x322a0bf4, 0xad4178aa, 0x3ef25309, 0xa59a07ae, 0xab1e9e79, 0x0ec4bd31, 0x7e0d0a83, 0x2c3009d8, 0x4a157237, 0xaa194909, 0x2481c8c1, 0x7b896259, 0xac994611, 0x3960ec97, 0x6c54eb6a, 0x58834127, 0x598c60ee, 0xb13ab9c4, 0x6aa9d9a5, 0xf5eb2cc2, 0x5b4de174, 0xdeaac61e, 0x3795623f, 0xcc973653, 0xb2b54e50, 0xbc26e53f, 0x4b6d12dc, 0x916fc058, 0xa185ef23, 0x6847313d, 0x3c839046, 0x3cc8a9de, 0xa50a1f7c, 0x02e5622f, 0xd2bdac47, 0x4d819fb9, 0xebded67b, 0x18562d73, 0x9bec65fc, 0x46a2415d, 0x752ccac4, 0x9dedcf21, 0xf0eeec13, 0x33dbf14a, 0xc810b5ca, 0x2709a859, 0xcd81ee57, 0xaa6e92cb, 0x004cceea, 0xbac402a4, 0xba19f371, 0x8c5d2333, 0x3d1e7773, 0xd09b54e7, 0x0eb5e19d, 0x67ad9f18, 0x8cb0dd14, 0xaf418f01, 0x00abd53d, 0x1bfc4f54, 0xb9d21733, 0x2db945fb, 0xa35aff0c, 0x5b443d85, 0x4ee48f8b, 0x85549957, 0xbf06ee3f, 0x9d4f9ce5, 0x3f5bfde5, 0xcf48b201, 0x82d3a530, 0x8f3345a5, 0xbe9538a9, 0x2fababd6, 0x15ebd5e7, 0xe4962910, 0x88063b18, 0xeb33fa79, 0xefeba5e7, 0x9b49152f, 0x83247d4e, 0xd3d7e978, 0xc618e8d4, 0x9e3ca84f, 0x6bbcd509, 0xfcb15ca5, 0x514af11f, 0xf21c5544};
uint32_t op1_5[128] = {0xda81b683, 0x784ccf7f, 0x2498c9af, 0xfb6ae5fe, 0x564f47f1, 0xea22d2e2, 0xd6354a59, 0xce102718, 0x39333e98, 0x725afae7, 0x25d7a3c7, 0x389d0a4d, 0x69c18595, 0xea53aa36, 0xc22b667e, 0x6d832209, 0xba4b5b80, 0x82eef63d, 0x999cbd2a, 0x39a03949, 0x700bc7e2, 0xaaa1d62a, 0xdeaf59df, 0x5510b53a, 0x12ffc321, 0x0303340c, 0xb1c32510, 0xc5a5b6e9, 0xe9ae5a1e, 0x0a5ce61d, 0x1aaca95f, 0x7348cf28, 0xc8bce6cd, 0x5662ca22, 0x717365ce, 0xd92bd7e1, 0x3bd7898b, 0x5c7129d5, 0x4201aa6e, 0xbf5c08d7, 0xa09dd93e, 0x3369c462, 0xd9c5dcde, 0x0a5589a2, 0x149116db, 0xded19186, 0x217fcaa8, 0x208c1412, 0xca73bcfc, 0x3a06e43b, 0x430761cc, 0x55108761, 0x4c33241b, 0x10bccaad, 0x88b0f89a, 0xe711add4, 0xfa612dc1, 0x4d5da6df, 0xc2cc2256, 0xb77e2d2b, 0xb4ac5878, 0x4aa1755e, 0xa82b0f8a, 0xaa3fc16d, 0x06dfb382, 0xcb94f4de, 0xf54308d8, 0x0254c445, 0x50b35483, 0xdacc86d3, 0x00efdb73, 0x81b384d8, 0xd26e9a4a, 0x59641b89, 0x386b655d, 0x15596f22, 0x4573e386, 0xe6d04654, 0x7fc44274, 0x64d8f139, 0x05657f96, 0x8387f7c4, 0x336cb380, 0x852edd1f, 0xe8268a81, 0xe169a80f, 0x5f1f72ef, 0x6907948f, 0x0b1c170b, 0x9672830e, 0x259dac76, 0xa1599933, 0x4d5bbeaa, 0x6faf199f, 0x2f1949a6, 0xe1f7531e, 0x31f1abdd, 0x457d56cf, 0x6eb1a55e, 0x1b5970b5, 0x0e185392, 0xcd957eb7, 0x396ac463, 0x1f0328cd, 0x3391e28b, 0x640d277e, 0x0de3cf8c, 0x35b35add, 0x8ea07f26, 0xf08110f0, 0x298053c0, 0x83480296, 0x88b77c17, 0xbe3881e2, 0xfa01ac9d, 0xbfd0a02d, 0xe1584860, 0x8cd4e987, 0x277a6240, 0x513bfb4f, 0x5711c62d, 0xc7f8a9a8, 0x89f8a366, 0xde1dc8fa, 0xba4f6e38, 0xd9114bc1, 0x8f83cfb6, 0x13728fca};
uint32_t op2_5[64] = {0xb422e9d5, 0xfd312c65, 0x6c544b0a, 0x8049b9d7, 0x227dfcf7, 0xf733d13d, 0xde966c32, 0x65662557, 0x00deea3c, 0x643b8949, 0x04ef197e, 0xd1eaa773, 0x91a4a71f, 0x68807cb3, 0x47a79e54, 0x646bdbe5, 0x33a3c00e, 0x6e250408, 0xf646a991, 0x66044769, 0x61e25a21, 0x16353f09, 0x278824be, 0x6d5a219f, 0xeff042db, 0x30034f5e, 0xc2c15b9b, 0xb7816eb4, 0xb405471d, 0x6985e77e, 0xdb27b24b, 0xb864ae4f, 0x68c2e8f4, 0x63f9679a, 0x66c1b23d, 0x589bff8a, 0xd8d630cf, 0xf0c13f07, 0x64371932, 0xd442985d, 0x0c971c30, 0xebacf86d, 0xd8adc591, 0x20178924, 0x34c10e5c, 0xd9262964, 0x67d3d5f3, 0x1e49a37f, 0xd168b179, 0xa509078e, 0xc1b2472c, 0x53fdc747, 0xb7cd29c0, 0x170b5f64, 0xa0bd932c, 0xea43b410, 0xc81556ab, 0xdb760897, 0x63982911, 0x12628876, 0x733fe851, 0x7b7168a8, 0xe58d4cd0, 0x2b7db9cd};
uint32_t res_5[128] = {0xda81b683, 0x784ccf7f, 0x2498c9af, 0xfb6ae5fe, 0x564f47f1, 0xea22d2e2, 0xd6354a59, 0xce102718, 0x39333e98, 0x725afae7, 0x25d7a3c7, 0x389d0a4d, 0x69c18595, 0xea53aa36, 0xc22b667e, 0x6d832209, 0xba4b5b80, 0x82eef63d, 0x999cbd2a, 0x39a03949, 0x700bc7e2, 0xaaa1d62a, 0xdeaf59df, 0x5510b53a, 0x12ffc321, 0x0303340c, 0xb1c32510, 0xc5a5b6e9, 0xe9ae5a1e, 0x0a5ce61d, 0x1aaca95f, 0x7348cf28, 0xc8bce6cd, 0x5662ca22, 0x717365ce, 0xd92bd7e1, 0x3bd7898b, 0x5c7129d5, 0x4201aa6e, 0xbf5c08d7, 0xa09dd93e, 0x3369c462, 0xd9c5dcde, 0x0a5589a2, 0x149116db, 0xded19186, 0x217fcaa8, 0x208c1412, 0xca73bcfc, 0x3a06e43b, 0x430761cc, 0x55108761, 0x4c33241b, 0x10bccaad, 0x88b0f89a, 0xe711add4, 0xfa612dc1, 0x4d5da6df, 0xc2cc2256, 0xb77e2d2b, 0xb4ac5878, 0x4aa1755e, 0xa82b0f8a, 0xaa3fc16d, 0xbb029d58, 0xc8c62144, 0x619753e2, 0x829e7e1c, 0x7331517b, 0xd2005810, 0xdf8647a5, 0xe719aa2f, 0xd34d8486, 0xbd9fa4d2, 0x3d5a7edb, 0xe7441695, 0xd7188aa6, 0x4f50c307, 0xc76be0c8, 0xc944cd1e, 0x39093fa4, 0xf1acfbcd, 0x29b35d11, 0xeb332489, 0x4a08e4a2, 0xf79ee718, 0x86a797ad, 0xd661b62e, 0xfb0c59e6, 0xc675d26c, 0xe85f0812, 0x58db07e8, 0x016105c7, 0xd935011e, 0x0a40fbf2, 0x9a5c016d, 0x9ab494d1, 0xa976be69, 0xd573579b, 0x73f5703f, 0xe6ee8462, 0xbe56bdbe, 0x9da1dd95, 0xf345c12a, 0x4028febc, 0x4fba1feb, 0xe691951d, 0x55cae401, 0xc3618d83, 0xc9a73a54, 0x915429b3, 0xa191a616, 0x5a202d91, 0x63418971, 0xbbb3f3ca, 0x13ce6775, 0x99257220, 0xa3e048eb, 0xc837f56d, 0x3b7faf60, 0x1f271cd9, 0xa36eb23f, 0xed90cc77, 0xf0805171, 0x2d8f568a, 0x5482b46a, 0x75111c86, 0x3ef04997};
uint32_t op1_6[128] = {0xd8cbaa4b, 0xc185bdd5, 0x063cbc12, 0x46ff4e18, 0xa68c0d70, 0x20a510b0, 0x960832c5, 0x3bf40c5b, 0x991215da, 0x8913f3de, 0x88a654ef, 0xd3366a73, 0x29b88153, 0xf95b24ea, 0x3b4191c2, 0x2a7b9161, 0xf708a3ed, 0x293c26a6, 0x6369d51a, 0x5f3a1e27, 0x24825fdc, 0xdc1df27a, 0xd7bb2ed4, 0xff57c91b, 0x1efdc678, 0xbceb68e7, 0x5142867d, 0xe83a2022, 0xbcd36ab3, 0x598f6576, 0x7b779660, 0x138f2d11, 0xace689f4, 0xcd23dc4b, 0xe4625ca5, 0x1387fafe, 0xa2722a0d, 0x219f5e86, 0x2065596d, 0x25436c92, 0x96fc361e, 0xac1c9734, 0xb7f79493, 0x660ca623, 0xef303ba9, 0x8063328c, 0xdfb22134, 0x334cbdb8, 0xae637281, 0x92c18b4d, 0xd3742257, 0xe3a52c88, 0x23c9d615, 0x14d870fc, 0x3ef7e8e4, 0x2ae03d90, 0xa66dc40c, 0x1e51b5d6, 0x95a4118f, 0x9c359a9a, 0x5ceac8b7, 0xb393983f, 0x55cf20cb, 0x17a90e9c, 0xca8db527, 0x4721d952, 0xfdfeb0b5, 0xe0715581, 0x58ba3515, 0xc993ba01, 0x1df20374, 0x73f26d5f, 0x0285b228, 0x1c45b120, 0xeee646a3, 0x85d48197, 0x3ba81ebc, 0x33ad4554, 0xab9dfece, 0x7930f733, 0x070f8579, 0xaa7d3106, 0x528869de, 0x984074b0, 0xd188b966, 0x3f5fab76, 0x041ce3be, 0x3c4c70d2, 0xd3fa0f4d, 0x37f0415a, 0x6222d3cc, 0x811af8e6, 0xf2a5175c, 0xc6eca785, 0x92f2092c, 0x366cfcde, 0xe768c71d, 0x35ee4a65, 0x2589ab04, 0x3c9ed03b, 0x6b454b22, 0x94bffd3e, 0xabd33359, 0x535459ad, 0x5195eacd, 0x4cca5f63, 0xa1115fd6, 0x8b646273, 0xab4e0fe8, 0x3c305742, 0xf43f47da, 0xff848eda, 0xab50dbeb, 0x637cc40a, 0x39dcd805, 0xb146ba72, 0x24feb33c, 0x47f9908b, 0x21deac78, 0x21cd6665, 0xe148946d, 0x56b9b88a, 0xa76bae90, 0xc4c1d914, 0x4e322893, 0x70a4e745, 0xdb3ee7f1, 0xbf7ca74f};
uint32_t op2_6[64] = {0xb04e1ef2, 0xb75a9e1a, 0x60ccc991, 0x138e8be9, 0xa06059d3, 0x7c18d3c8, 0xe9be7f33, 0xfa3dd36c, 0xe921df0c, 0xff23cd07, 0xf9e79c79, 0x270a62b5, 0x1413437f, 0xab4973ab, 0xcc0839eb, 0x2adf3ffb, 0x2f916f3e, 0x795189cf, 0x2f716e56, 0x748ad929, 0xfbcb7476, 0x7f20d70f, 0x8bc53629, 0x6c5e56b7, 0x8c6b3139, 0xfc817c1c, 0xcf2587dd, 0xbf94d24b, 0x6b7a08fb, 0x86d5287d, 0xadf9fbe9, 0x6acf3541, 0x992f06a6, 0x7f64f029, 0x39e9a580, 0xf44538a4, 0x638ab3d5, 0xff591032, 0xf314f8c0, 0x3b64e7d6, 0xd96f143f, 0xc0c62d09, 0xba848d8e, 0xdaaa6ab9, 0xbd19b1e8, 0x281b9b19, 0x49b576f3, 0x5b81a3b8, 0xf8d848fb, 0x46c671f3, 0x63a09c79, 0xc4b4e700, 0x121cf2c5, 0x8278a6c2, 0xc011bf9e, 0xd7d18e24, 0xd8ec3d10, 0x5fd6fda0, 0x062b1b0f, 0xd9e89193, 0x7f371746, 0x2ce7497a, 0x767e08af, 0xf500417b};
uint32_t res_6[128] = {0xd8cbaa4b, 0xc185bdd5, 0x063cbc12, 0x46ff4e18, 0xa68c0d70, 0x20a510b0, 0x960832c5, 0x3bf40c5b, 0x991215da, 0x8913f3de, 0x88a654ef, 0xd3366a73, 0x29b88153, 0xf95b24ea, 0x3b4191c2, 0x2a7b9161, 0xf708a3ed, 0x293c26a6, 0x6369d51a, 0x5f3a1e27, 0x24825fdc, 0xdc1df27a, 0xd7bb2ed4, 0xff57c91b, 0x1efdc678, 0xbceb68e7, 0x5142867d, 0xe83a2022, 0xbcd36ab3, 0x598f6576, 0x7b779660, 0x138f2d11, 0xace689f4, 0xcd23dc4b, 0xe4625ca5, 0x1387fafe, 0xa2722a0d, 0x219f5e86, 0x2065596d, 0x25436c92, 0x96fc361e, 0xac1c9734, 0xb7f79493, 0x660ca623, 0xef303ba9, 0x8063328c, 0xdfb22134, 0x334cbdb8, 0xae637281, 0x92c18b4d, 0xd3742257, 0xe3a52c88, 0x23c9d615, 0x14d870fc, 0x3ef7e8e4, 0x2ae03d90, 0xa66dc40c, 0x1e51b5d6, 0x95a4118f, 0x9c359a9a, 0x5ceac8b7, 0xb393983f, 0x55cf20cb, 0x17a90e9d, 0x7adbd419, 0xfe7c776d, 0x5ecb7a46, 0xf3ffe16a, 0xf91a8ee9, 0x45ac8dca, 0x07b082a8, 0x6e3040cb, 0xeba79135, 0x1b697e28, 0xe8cde31c, 0xacdee44c, 0x4fbb623b, 0xdef6b900, 0x77a638b9, 0xa410372e, 0x36a0f4b8, 0x23cebad5, 0x81f9d835, 0x0ccb4dda, 0xcd542ddc, 0xbe808285, 0x8fe219e7, 0xa8aac78a, 0x60654087, 0x3471bd77, 0x31485baa, 0x40afcb32, 0x5e1f2058, 0x4dc1d003, 0x40ec0515, 0xa13c3220, 0x8097cdc3, 0xb5533a8e, 0x5f735085, 0x30e408df, 0xcecffef8, 0x94190d71, 0x9ee82c19, 0x8eb94184, 0x2b04ff0d, 0x0d908c6d, 0x5b95ed65, 0x660ecd2d, 0x6867c1d0, 0x644bf25c, 0x3df4bece, 0x5b063293, 0xa42924e6, 0xaa4335fd, 0x9d7d747f, 0x75fba172, 0x371ba601, 0xca72374d, 0xe1f06c16, 0xf99ef48a, 0xba34d17d, 0xb690b62a, 0xad96c9a0, 0x9eaa6aa7, 0xcd693fd9, 0x9d8c30c0, 0x51bcf0a1, 0xb47ce8ca};
uint32_t op1_7[128] = {0xd70bb63c, 0x3d5da27b, 0x391c66c8, 0x9779c5e8, 0x0c2c1d38, 0x2d50831c, 0x54373cd1, 0x83ec3ca0, 0x23671577, 0x11e1c766, 0xd77f7764, 0xca86a01a, 0xfef18f01, 0x0f5451e9, 0x86f2faa7, 0x7b0640b1, 0x4d8135a7, 0x072f3e19, 0x2c80f143, 0x64121ef1, 0xd191f76f, 0x6520a0c9, 0x6da902da, 0x58b565d4, 0x9b86717a, 0x7f8bcbf5, 0xafb28e3b, 0x7c308469, 0x76659e02, 0xd1f13aa6, 0x4966961c, 0xcc07bd74, 0x80f986c2, 0xf67293a4, 0xc7bfe7e8, 0xfba2e4fd, 0x841ddb90, 0x1254f4bd, 0xaa0a640f, 0xf0b308cb, 0xd10d5210, 0xf43ffb6e, 0x8c958e73, 0xbdb52d98, 0x4f02d226, 0x54131499, 0x30f400e9, 0x2da5596b, 0x494256b9, 0xd92b34ac, 0xedcf1506, 0x90aea475, 0x6c98cb50, 0xa8fc07e1, 0x74bcb248, 0x077ccd5d, 0xdf9138e5, 0x8da6db86, 0x0add9ef5, 0x177c955c, 0x27eb5b91, 0xc2d91da4, 0xf26cb5bd, 0xb574942d, 0xc0ff2bf5, 0xbb46afb7, 0xbbeea779, 0xa55d86f2, 0xa69e4574, 0xd5ddb9ca, 0x4ca08ac3, 0xc6a82fc4, 0x94864b3b, 0x2de5db49, 0x966abb20, 0x4c1432a0, 0xa2f4375b, 0x751d610c, 0x07fc12ce, 0xfc1a4d8e, 0x94f1bb51, 0x0c7f8050, 0x1b2cde60, 0x3c5cd66a, 0x6927e07f, 0x3af590fc, 0x634c226e, 0x486836fd, 0x341c7c0f, 0x19af69be, 0xb7762722, 0xd8bb1748, 0xeb790410, 0xf25ce6d5, 0xb78e90dd, 0x7f6e955c, 0xa1b6c6da, 0x2bcc59c4, 0x295152b9, 0x9d520e82, 0x5c8721cd, 0xdaa84fd6, 0x34965809, 0xc7c8a977, 0xe88a1728, 0xb2685055, 0x794981e6, 0x88a5eb1b, 0xfaeec462, 0x2909bf1f, 0x85e102b3, 0x00ff0830, 0x099141ef, 0xb9a3fa4f, 0xf7b374c2, 0x91d47271, 0x406fd874, 0x6c27074a, 0x709cd89d, 0xe243bede, 0x3944ca9b, 0xb5322f61, 0xd9da0afd, 0xe85302e5, 0xc8e763dc, 0x9ebe3f3c, 0x34f3618f, 0xdf810e1f};
uint32_t op2_7[64] = {0x947cff7f, 0x0935e55f, 0xbb33545a, 0xc1c05538, 0x76ee4e65, 0x1fba970e, 0x0b338ec8, 0x314226ea, 0x2b5a8efe, 0xa0635af5, 0x33cc1186, 0x91c8de1c, 0xe5672519, 0xd3ac5e84, 0x5526d902, 0xaf9cf34e, 0x0aaa8f86, 0x4458b6eb, 0x492aff59, 0xdb0e7b88, 0x49732d50, 0xe68f9eb6, 0xe2d43d28, 0xeb3371c3, 0xecea0ee1, 0xfca1b447, 0x13c7debb, 0x6cc1e81b, 0xb0c6fdb0, 0x936622b8, 0x7b70a3ec, 0x029f9e38, 0x69a2bcb2, 0xcd5a6411, 0x63c55dc0, 0x2b6425c5, 0x9aa03996, 0x21f6b4ac, 0x4155cf3c, 0xda78d538, 0xe6007785, 0xa6e76746, 0x4319b617, 0x31c9fea8, 0x7f1d291f, 0x63139b5a, 0x41f300e5, 0x03747ff7, 0x024bd00d, 0xcbc8a667, 0x7e403297, 0xf1e9ce74, 0x1f0fdce3, 0x4455416d, 0x815687c8, 0x063ccee6, 0x9c077cdb, 0x4eb9fa34, 0x272014ab, 0xb1fd9b41, 0xa8b4a87f, 0x4acd8259, 0x1110bf9d, 0xab6e0f55};
uint32_t res_7[128] = {0xd70bb63c, 0x3d5da27b, 0x391c66c8, 0x9779c5e8, 0x0c2c1d38, 0x2d50831c, 0x54373cd1, 0x83ec3ca0, 0x23671577, 0x11e1c766, 0xd77f7764, 0xca86a01a, 0xfef18f01, 0x0f5451e9, 0x86f2faa7, 0x7b0640b1, 0x4d8135a7, 0x072f3e19, 0x2c80f143, 0x64121ef1, 0xd191f76f, 0x6520a0c9, 0x6da902da, 0x58b565d4, 0x9b86717a, 0x7f8bcbf5, 0xafb28e3b, 0x7c308469, 0x76659e02, 0xd1f13aa6, 0x4966961c, 0xcc07bd74, 0x80f986c2, 0xf67293a4, 0xc7bfe7e8, 0xfba2e4fd, 0x841ddb90, 0x1254f4bd, 0xaa0a640f, 0xf0b308cb, 0xd10d5210, 0xf43ffb6e, 0x8c958e73, 0xbdb52d98, 0x4f02d226, 0x54131499, 0x30f400e9, 0x2da5596b, 0x494256b9, 0xd92b34ac, 0xedcf1506, 0x90aea475, 0x6c98cb50, 0xa8fc07e1, 0x74bcb248, 0x077ccd5d, 0xdf9138e5, 0x8da6db86, 0x0add9ef5, 0x177c955c, 0x27eb5b91, 0xc2d91da4, 0xf26cb5bd, 0xb574942e, 0x557c2b74, 0xc47c9517, 0x7721fbd4, 0x671ddc2b, 0x1d8c93d9, 0xf59850d8, 0x57d4198b, 0xf7ea56ae, 0xbfe0da39, 0xce49363e, 0xca36cca6, 0xdddd10bd, 0x885b5c75, 0x48c9bf90, 0x5d22ebd1, 0xabb740dc, 0x9f9c4ad7, 0x50d8373b, 0x6457ddba, 0x176b51f2, 0xb29b0dd0, 0x21852fb3, 0x46205f97, 0x339ba8c1, 0x21068af1, 0x16511e05, 0xcb3e05de, 0x457cff64, 0x9c4001c1, 0x85c3098e, 0x32ff34c9, 0x820e3395, 0x0b59838c, 0xf926bdd5, 0x8d16b079, 0xc8b63447, 0xf7275b63, 0xfc9f0482, 0x75ec2746, 0xa2417eb0, 0xce8a8eae, 0x594fb79b, 0xbc6337fd, 0xba6fe9c4, 0x7a0bed81, 0x8c1d5a79, 0xc7d40398, 0x04738827, 0x0bdd11fd, 0x856ca0b7, 0x75f3a75a, 0x83be40e5, 0x5f7fb557, 0xb07c48b7, 0xf1f36065, 0xe8808dc4, 0xd54c4777, 0x03ec2996, 0x00fa1fa9, 0x9a509e27, 0x719c0c5b, 0xe98bc195, 0x4604212d, 0x8aef1d74};
uint32_t op1_8[128] = {0xa13f2b24, 0xf0545b67, 0x6e004352, 0x16839860, 0x3323cd39, 0xf1c94df8, 0xd96f9aa3, 0xd386f8dd, 0x20a5c627, 0xdcc5981c, 0xce38b4ab, 0x817e111c, 0x2e231e7e, 0x6f940fff, 0x8fc09379, 0x4806e285, 0x17e63d72, 0x9c11bf0e, 0xcb9997f8, 0xbec0c8d2, 0x7cca2a38, 0x91673ecd, 0x6256c8a6, 0xd4cec597, 0x529b32e9, 0xc594b2a9, 0xc1843f08, 0x93804009, 0x74418954, 0x02457f67, 0x7b2103fa, 0xd66cc575, 0xb249a668, 0xcc6b39e3, 0x5084e132, 0x49accf76, 0x1e9fe0c4, 0x18f8cd11, 0xa5d7785a, 0xb30d1e47, 0x010a6c89, 0xb81f4c76, 0x3cbee3c4, 0xcbe3f2db, 0xabbe1b50, 0x6fcec92b, 0x7f54c7a3, 0x18a52b0b, 0x6e48218d, 0x99e9b42a, 0x859d8258, 0xef953162, 0xcfead977, 0x0bad317e, 0x7ab554f7, 0x6d79ce0c, 0xd2dfc3cc, 0xdfa00321, 0x3ae699d5, 0x367ba1ef, 0x12132d4b, 0x6a5d4934, 0xf8d36a7f, 0x2488d323, 0x3a871e30, 0xd6527ab0, 0x5a806fd5, 0x12c7d278, 0x850c1292, 0x27f6d686, 0x09e39678, 0x99690916, 0xf6b73d2a, 0x415edcf1, 0xc7a73157, 0x88718c51, 0xdf9069c0, 0x2477770f, 0x3e8cf781, 0xcb0362a9, 0xc406a3e0, 0x321713dc, 0xfa694604, 0xc2789752, 0x128e1986, 0x01d8e6c0, 0x7efea1c2, 0xab6a4017, 0x162ec9cd, 0xec1d1af7, 0xf28d44ee, 0x0ed4bc25, 0x4b2c7f3e, 0x5f2995bc, 0x61773e5b, 0xf1b8f645, 0xc4e2d80b, 0x24a0a1d8, 0xffe3e03e, 0x8579322e, 0x246d72e4, 0x84c50b83, 0xa2f6dc18, 0x583757e7, 0x2b31f4f2, 0x7d414b9c, 0x490ac518, 0x60eae2e8, 0xd8504d72, 0x53c7d7a6, 0x0a4e2d25, 0x9e580ab4, 0xd654e93f, 0xf9eb774e, 0x8b75a3b7, 0xcb0cd006, 0x37c043c1, 0xdd6b0dee, 0xe2230adc, 0xa2ba9a54, 0x290970c1, 0x3d04dda1, 0xf62a88b8, 0xcbe5776d, 0xf447c00d, 0xc2d491f0, 0x4d06953f, 0x1cbef0c2};
uint32_t op2_8[64] = {0xf3881338, 0x1c68d6e4, 0x1a18da99, 0xd98b09f7, 0x5a6b8096, 0xa92c5d28, 0x427bfdab, 0x95bc9c5c, 0x8d9623cf, 0x62ebceec, 0xfa15d67f, 0xe40c64cf, 0x47c092a6, 0x73f12ee9, 0xa0a5db67, 0xd9485bbc, 0xcaa18d2f, 0xad25b8f2, 0x6c20b70b, 0x13d7ae61, 0x9227d909, 0x109fd085, 0x912a44a7, 0x674a6f50, 0xd24c7746, 0x98c43de0, 0x3b472c34, 0x3b0f225c, 0x570f8a5f, 0xf4652ddf, 0x697aa42d, 0xc7889493, 0x4b4d226b, 0xf3a58d9b, 0x929710b7, 0x4ac9c343, 0x13cd7505, 0x158051eb, 0xb25b29f9, 0x8445c177, 0xc2177b74, 0x72a72d80, 0xb7c04960, 0x1b98f9ef, 0x58287291, 0xe3e7fa5c, 0x6a06637c, 0x076b0a26, 0x2cc45687, 0x11e7f722, 0xa247953b, 0xb65f8c60, 0x03142242, 0x20e8e9be, 0x9798a14b, 0x1bac8de9, 0xe26404ba, 0x4c712c49, 0x8209accd, 0xbbc55e95, 0x72474a80, 0xf33519c4, 0x3d0c623d, 0x53392d2b};
uint32_t res_8[128] = {0xa13f2b24, 0xf0545b67, 0x6e004352, 0x16839860, 0x3323cd39, 0xf1c94df8, 0xd96f9aa3, 0xd386f8dd, 0x20a5c627, 0xdcc5981c, 0xce38b4ab, 0x817e111c, 0x2e231e7e, 0x6f940fff, 0x8fc09379, 0x4806e285, 0x17e63d72, 0x9c11bf0e, 0xcb9997f8, 0xbec0c8d2, 0x7cca2a38, 0x91673ecd, 0x6256c8a6, 0xd4cec597, 0x529b32e9, 0xc594b2a9, 0xc1843f08, 0x93804009, 0x74418954, 0x02457f67, 0x7b2103fa, 0xd66cc575, 0xb249a668, 0xcc6b39e3, 0x5084e132, 0x49accf76, 0x1e9fe0c4, 0x18f8cd11, 0xa5d7785a, 0xb30d1e47, 0x010a6c89, 0xb81f4c76, 0x3cbee3c4, 0xcbe3f2db, 0xabbe1b50, 0x6fcec92b, 0x7f54c7a3, 0x18a52b0b, 0x6e48218d, 0x99e9b42a, 0x859d8258, 0xef953162, 0xcfead977, 0x0bad317e, 0x7ab554f7, 0x6d79ce0c, 0xd2dfc3cc, 0xdfa00321, 0x3ae699d5, 0x367ba1ef, 0x12132d4b, 0x6a5d4934, 0xf8d36a7f, 0x2488d324, 0x2e0f3168, 0xf2bb5194, 0x74994a6e, 0xec52dc6f, 0xdf779328, 0xd12333ae, 0x4c5f9424, 0x2f25a573, 0x844d60f9, 0xa44aabde, 0xc1bd07d7, 0x6c7df121, 0x2750fc66, 0x9868a5f8, 0xdf32d2e9, 0xa44bbe66, 0x8ea8310f, 0xdf3ccccf, 0x6689fd0f, 0xd65045b3, 0xa4b5f28f, 0x1278b746, 0x1028e66a, 0x12b4af67, 0xe87b4114, 0x84e158d8, 0x2dd47122, 0x49e3de81, 0xa23c099e, 0x538ec39b, 0xcaf1e289, 0xb9418ad9, 0x102ffa77, 0x18462f74, 0x927af0f5, 0xd042f571, 0x383ae7e9, 0x9a455d6f, 0x55520611, 0xdc7d195e, 0xed497066, 0xefe8791d, 0x00cb0e78, 0x7c83dcd8, 0x3078c004, 0x37afd202, 0x745490a1, 0xa5c314db, 0x03193fc7, 0x0bd36e71, 0x2dbd38f3, 0x816c5c66, 0x3ad46603, 0xfe53f7ad, 0x79bbac27, 0xbe67283e, 0x0b6d757b, 0x897609eb, 0x78343586, 0x87aad603, 0x668f0a8e, 0xb609abb4, 0x8a12f77c, 0x6ff81ded};
uint32_t op1_9[128] = {0xa9b971d2, 0x8d32e2de, 0x46a13507, 0x1f9b9836, 0x72dde67c, 0x7f0d80d8, 0xe263977c, 0x8dbcd5b7, 0x0108a886, 0x4fa790ee, 0xbb882ac3, 0xdfc94c58, 0xa819fe67, 0x349f247d, 0x20e2238f, 0x1274786b, 0x8fbfbdc1, 0x6aeffc1c, 0x264cde24, 0xc1366bd0, 0x53f58a1f, 0x1a41bf19, 0x3c073787, 0x69d32807, 0x5ec40461, 0x30f2289c, 0xfe777bab, 0x16cb5eb9, 0x544e6b3c, 0x14393f97, 0x776be35a, 0x5fd7006f, 0x869b2dab, 0x7e3ae460, 0x0ba8c6a1, 0x80aea1ee, 0x3f3abf01, 0x26169abd, 0xa1b3a5a5, 0x83281c6c, 0xe2f1b9ef, 0x5fb86d6a, 0xe8b7af71, 0x19d9f199, 0x07150ae6, 0x5f7d2777, 0x45be0244, 0x1a83cfbe, 0xea18d13d, 0x9a646e01, 0xc213d1ac, 0xa593d9e4, 0x7d8290a7, 0xedd0e013, 0x87639e3b, 0x968bf15f, 0x2592c338, 0x808b4081, 0x4da42568, 0x52e2cd1f, 0x171fdabb, 0x718dfce4, 0x74a61b37, 0xfb351e8c, 0x2a224b39, 0x111e843f, 0x385dedcd, 0x630a2d81, 0x8fb81b95, 0x6a55dd51, 0xa284190f, 0x5a9d3fe2, 0x120ec512, 0xf5a1bbb8, 0x1f7b4e92, 0xdc4f537a, 0x3d09c1e1, 0xd079bb33, 0xddf6ee24, 0x0e984281, 0xbfb939b2, 0x6ee85721, 0x5730b63e, 0xe9b613f6, 0xd1af9c99, 0x10ec3480, 0xb7985f04, 0x0e044c3c, 0x54d9f36b, 0xd13b6d2e, 0xfc5a2b52, 0xdec857cc, 0x44704072, 0x5f9f5c66, 0x7cc1fbfc, 0x2da19ad7, 0xa4e480ed, 0x53db4c76, 0x321bf6b7, 0xc7ce4d83, 0x67ed17bd, 0xcf779665, 0xcd221ff9, 0x5d88484b, 0x6eeda7e2, 0x6e86cb9d, 0x1f103868, 0xb75bc00f, 0x48e3ada1, 0x37cdb574, 0x7aef2f8d, 0x6a018904, 0x67a6d5f1, 0xac448496, 0x056520fb, 0x2f2e1c16, 0x4ed5501c, 0xee0a59a7, 0x2b0163e4, 0xe3729b64, 0x98560313, 0x64c55fab, 0x82d672c9, 0xee0adab7, 0x6389a23d, 0xedb3ea3c, 0xa9bb3869, 0x3b958ae6};
uint32_t op2_9[64] = {0xa64058f2, 0x8e453baf, 0x32da946a, 0x174612fc, 0x913e7c0a, 0xa69cf6a6, 0x8feff9e0, 0x5629225a, 0x8b878e1c, 0x1fef7725, 0x1e281fc3, 0xd478e83f, 0x531c12cb, 0x1f8c9474, 0xc9b0c7e3, 0x3d045f48, 0x6852df8c, 0xb37366b5, 0xcaf9c529, 0x6c2686ca, 0x9d29f084, 0xc7ac8e94, 0x64e506da, 0x0dcaed67, 0x09ac19af, 0x20f3cbfa, 0x865d6bb8, 0xc9460219, 0x11835bda, 0x82c67fdc, 0x3b600158, 0x278752dd, 0x8d5e8c4f, 0x7f27ab00, 0xf8e3fce9, 0x6eb061f2, 0xaa68517f, 0x9a3cb289, 0x6669e376, 0xf1786bc4, 0x5b4ad0ac, 0xdc197964, 0xf246b2f2, 0x265f2485, 0x7a474ea6, 0x09fae05d, 0x12aea940, 0x79db57fa, 0xcfb754c6, 0xe08fd088, 0xf1ca0d07, 0x56998537, 0xe7277ab4, 0x1d035f66, 0xa0e3b1e2, 0xafcb8cab, 0x59ed44c3, 0x65daaabb, 0x8cec3044, 0xe5c9359f, 0x6ab263bb, 0x27ff2d36, 0x8e475bed, 0xcf08c551};
uint32_t res_9[128] = {0xa9b971d2, 0x8d32e2de, 0x46a13507, 0x1f9b9836, 0x72dde67c, 0x7f0d80d8, 0xe263977c, 0x8dbcd5b7, 0x0108a886, 0x4fa790ee, 0xbb882ac3, 0xdfc94c58, 0xa819fe67, 0x349f247d, 0x20e2238f, 0x1274786b, 0x8fbfbdc1, 0x6aeffc1c, 0x264cde24, 0xc1366bd0, 0x53f58a1f, 0x1a41bf19, 0x3c073787, 0x69d32807, 0x5ec40461, 0x30f2289c, 0xfe777bab, 0x16cb5eb9, 0x544e6b3c, 0x14393f97, 0x776be35a, 0x5fd7006f, 0x869b2dab, 0x7e3ae460, 0x0ba8c6a1, 0x80aea1ee, 0x3f3abf01, 0x26169abd, 0xa1b3a5a5, 0x83281c6c, 0xe2f1b9ef, 0x5fb86d6a, 0xe8b7af71, 0x19d9f199, 0x07150ae6, 0x5f7d2777, 0x45be0244, 0x1a83cfbe, 0xea18d13d, 0x9a646e01, 0xc213d1ac, 0xa593d9e4, 0x7d8290a7, 0xedd0e013, 0x87639e3b, 0x968bf15f, 0x2592c338, 0x808b4081, 0x4da42568, 0x52e2cd1f, 0x171fdabb, 0x718dfce4, 0x74a61b37, 0xfb351e8c, 0xd062a42b, 0x9f63bfee, 0x6b388237, 0x7a50407e, 0x20f697a0, 0x10f2d3f8, 0x327412ef, 0xb0c6623c, 0x9d96532f, 0x159132dd, 0x3da36e56, 0xb0c83bb9, 0x9025d4ac, 0xf0064fa8, 0xa7a7b607, 0x4b9ca1ca, 0x280c193f, 0x225bbdd7, 0x222a7b68, 0x55dc9ac1, 0x6ed98d1d, 0xd898c315, 0x1c7d65de, 0x1bcf39a3, 0x5e860d1a, 0xf22f3929, 0x82b7970b, 0xa80e59e5, 0x55f39c4c, 0xe265dc42, 0xb821fd54, 0x5528edb5, 0x32430d3c, 0xd302f777, 0x2afff3a1, 0x367eaf76, 0x1255693d, 0x69b448ef, 0x338c0370, 0x4f00b40f, 0xca38788f, 0x4aa04502, 0x1156eb5a, 0xddbae494, 0xc32afc47, 0x41c895d1, 0x8d9dd8cd, 0xe3dce0ff, 0x375e2ab8, 0x8cd4551e, 0xf72f2e02, 0x85c7a14e, 0x35fccad1, 0x0b0db90d, 0xcbe515c7, 0x933e280f, 0xf24347d6, 0xcaa00a67, 0x0fc2a30e, 0xd3d41056, 0xce3c05f9, 0x15b31773, 0x38029457, 0x0a9e5037};
int nDigop1[10] = {128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
int nDigop2[10] = {64, 64, 64, 64, 64, 64, 64, 64, 64, 64};
int nDigres[10] = {128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
uint32_t *op1[] = {op1_0, op1_1, op1_2, op1_3, op1_4, op1_5, op1_6, op1_7, op1_8, op1_9};

uint32_t *op2[] = {op2_0, op2_1, op2_2, op2_3, op2_4, op2_5, op2_6, op2_7, op2_8, op2_9};

uint32_t *res[] = {res_0, res_1, res_2, res_3, res_4, res_5, res_6, res_7, res_8, res_9};


#endif