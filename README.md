# RT
## 42 Graphic Project	by cpierre

### User-side features:
- [ ] 3 different file formats are handled
    * [ ] .rt
    * [ ] .xml
    * [ ] .json

- [ ] can create a new empty map using `./rt create <filename>`
    * [ ] fills it with basic stuff
    * [x] saves it in maps folder

- [ ] can render a file with `./rt render <filename>`
	* [ ] while rendering, can play an Undertale mini-game
		* [ ] determination
		* [ ] patience
		* [ ] bravery
		* [ ] integrity
		* [ ] perseverance
		* [ ] kindness
		* [ ] justice
	* [ ] full render
		* [ ] basic shapes
			* [ ] plane
			* [ ] sphere
			* [ ] cylinder
			* [ ] cone
		* [ ] composed shapes
			* [ ] simple face
			* [ ] multi-face objects
		* [ ] shadows
			* [ ] multiple lights
			* [ ] smooth effect
		* [ ] texture mapping
			* [ ] .jpeg
			* [ ] .bmp
			* [ ] .png
		* [ ] bump mapping
		* [ ] ambient occlusion
		* [ ] reflexions
		* [ ] transparency
		* [ ] render image saving
		* [ ] multiple camera movie rendering
		* [ ] skybox
		* [ ] fog
		* [ ] radiance

- [ ] can edit file with `./rt edit <filename>`
	* [ ] file save ability at any time
	* [ ] ability to affect multiple render variables
		* [ ] ambient occlusion
		* [ ] skybox texture
		* [ ] radiance
			* [ ] on / off
			* [ ] radiance power
			* [ ] radiance iterations
		* [ ] objects
			* [ ] ability to interact with any object by selecting it with mouse
				* [ ] for each selected object, a window to change object settings
			* [ ] cameras
				* [ ] camera fov
					* [ ] real-time with mouse wheel
				* [ ] camera position
					* [ ] real-time positioning with keyboard
				* [ ] camera angle
					* [ ] real-time positioning with mouse
				* [ ] camera count
					* [ ] add/delete with key up/down
					* [ ] move through cameras with key left/right
			* [ ] lights
				* [ ] light position
				* [ ] light count
			* [ ] shapes
				* [ ] shape count
				* [ ] shape type
				* [ ] shape position
				* [ ] shape rotations
				* [ ] shape reflexion index
				* [ ] shape transparency index
				* [ ] shape texture
				* [ ] shape bump-map
