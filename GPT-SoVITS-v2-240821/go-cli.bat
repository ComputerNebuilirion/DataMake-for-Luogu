cd GPT-SoVITS-v2-240821
runtime\python.exe GPT_SoVITS/inference_cli.py --gpt_model GPT_weights_v2\流萤-e10.ckpt --sovits_model SoVITS_weights_v2\流萤_e15_s810.pth --ref_audio firefly\ref_audio\example.wav --ref_text ref_text.txt --ref_language 中文 --target_text target_text.txt --target_language 中文 --output_path output